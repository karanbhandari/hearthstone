#include <string>
#include <sstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "Deck.h"
#include "Card.h"
#include "Spells.h"
#include "Minion.h"
#include "Enchantment.h"
#include "Ability.h"
#include "Ritual.h"

#define DBG true
using namespace std;

// Creates a new deck object and fills it with cards from the .deck file as specified

Deck::Deck(istream& deckList) :
		AbstractDeck {0, 30} {
	string currentCardName;
	int deckSize = 0;

	// Adds all the cards in the .deck file to the deck list
	while (deckList) {
		getline(deckList, currentCardName);
		Card *card = createCard(currentCardName);
		if (card) {
			if (DBG) cout << "Enter" << endl;	
			cardList.emplace_back(card);
			deckSize++;
		}
	}

	// sets the deck Size to number of cards added above
	size = deckSize;
}

// Creates a new card specific to the name of the card given
Card* Deck::createCard(string name) {

	// For All Spell Cards
	// All Spell Cards are initiated in the format: new Spell (string name, int magicCost, Ability ability)
	cout<<"name of Card being added: "<<name<<endl;
	if (name == "Banish") {
		const string abilityName = "Destroy target minion or ritual";
		const string spellName = "Banish";
		Ability * banishAb = new ActivatedAbility(abilityName); // TODO: @Karan Change Ability to activatedAbility
		Spell * banish = new Spell(spellName, 2, banishAb);
		return banish;
	} else if (name == "Unsummon") {
		const string abilityName = "Return target minion to its owners hand"; // TODO: @Karan Change ability to activated ability
		const string spellName = "Unsummon";
		Ability * unsummonAb = new ActivatedAbility(abilityName);
		Spell * unsummon = new Spell(spellName, 1, unsummonAb);
		return unsummon;
	} else if (name == "Recharge") {
		const string abilityName = "Your ritual gains 3 charges"; // TODO: @Karan Change ability to ActivatedAbility
		const string spellName = "Recharge";
		Ability * rechargeAb = new ActivatedAbility(abilityName);
		Spell * recharge = new Spell(spellName, 1, rechargeAb);
		return recharge;
	} else if (name == "Disenchant") {
		const string abilityName = "Destroy the top enchantment on target minion"; // TODO: @Karan Change ability to activatedAbility
		const string spellName = "Disenchant";
		Ability * disenchantAb = new ActivatedAbility(abilityName);
		Spell * disenchant = new Spell(spellName, 1, disenchantAb);
		return disenchant;
	} else if (name == "Raise Dead") {
		const string abilityName = "Resurrect the top minion in your graveyard and set its defence to 1"; // TODO: @Karan Change aility to activated abiility
		const string spellName = "Raise Dead";
		Ability * raiseDeadAb = new ActivatedAbility(abilityName);
		Spell * raiseDead = new Spell(spellName, 1, raiseDeadAb);
		return raiseDead;
	} else if (name == "Blizzard") {
		const string abilityName = "Deal 2 damage to all minions"; // TODO: @Karan change ability to activated ability
		const string spellName = "Blizzard";
		Ability * BlizzardAb = new ActivatedAbility(abilityName);
		Spell * Blizzard = new Spell(spellName, 3, BlizzardAb);
		return Blizzard;
	}

	// For all Minion Cards
	// All Minion Cards are initated in the format:
	// new Minion (int attack, int defence, int magicCost, Ability ActivatedAbility,
	// Ability triggeredAbility, Ability newestActivatedAbility)
	// I'm not sure what the last ability is? I'm guessing its the buff right?
	else if (name == "Air Elemental") {
		const string minionName = "Air Elemental";
		Ability * actAb = nullptr;
		Ability * trigAb = nullptr;
		Minion * myMinion = new Minion(minionName, 1, 1, 0, actAb, trigAb);
		return myMinion;
	} else if (name == "Earth Elemental") {
		const string minionName = "Earth Elemental";
		Ability * actAb = nullptr;
		Ability * trigAb = nullptr;
		Minion * myMinion = new Minion(minionName, 4, 4, 3, actAb, trigAb);
		return myMinion;
	} else if (name == "Bone Golem") {
		const string minionName = "Bone Golem";
		const string abilityName = "Gain +1/+1 whenever a minion leaves play.";
		Ability * actAb = nullptr;
		Ability * trigAb = new TriggeredAbility(abilityName); // TODO: @Karan change ability to triggered ability
		Minion * myMinion = new Minion(minionName, 1, 3, 2, actAb, trigAb);
		return myMinion;
	} else if (name == "Fire Elemental") {
		const string minionName = "Fire Elemental";
		const string abilityName = "Whenever an opponents minion enters play, deal 1 damage to it.";
		Ability * actAb = nullptr;
		Ability * trigAb = new TriggeredAbility(abilityName); // TODO: @Karan change ability to triggered ability
		Minion * myMinion = new Minion(minionName, 2, 2, 2, actAb, trigAb);
		return myMinion;
	} else if (name == "Potion Seller") {
		const string minionName = "Potion Seller";
		const string abilityName = "At the end of your turn, all your minions gain +0/+1."; 		
		Ability * actAb = nullptr;
		Ability * trigAb = new TriggeredAbility(abilityName); // TODO: @Karan change ability to triggered ability
		Minion * myMinion = new Minion(minionName, 1, 3, 2, actAb, trigAb);
		return myMinion;

		// need to update a cost for activating ability when ability class done
	} else if (name == "Novice Pyromancer") {
		const string minionName = "Novice Pyromancer";
		const string abilityName = "Deal 1 damage to target minion";
		Ability * actAb = new ActivatedAbility(abilityName);
		Ability * trigAb = nullptr;
		Minion * myMinion = new Minion(minionName, 0, 1, 1, actAb, trigAb);
		return myMinion;
	} else if (name == "Apprentice Summoner") {
		const string minionName = "Apprentice Summoner";
		const string abilityName = "Summon a 1/1 air elemental";
		Ability * actAb = new ActivatedAbility(abilityName);
		Ability * trigAb = nullptr;
		Minion * myMinion = new Minion(minionName, 1, 1, 1, actAb, trigAb);
		return myMinion;
	} else if (name == "Master Summoner") {
		const string minionName = "Master Summoner";
		const string abilityName = "Summon up to three 1/1 air elementals";
		Ability * actAb = new ActivatedAbility(abilityName);
		Ability * trigAb = nullptr;
		Minion * myMinion = new Minion(minionName, 2, 3, 3, actAb, trigAb);
		return myMinion;
	}
	// Enchantment Cards goes here:
	//Enchantment::Enchantment(const string &name, int cost, int changeAttack, int changeDefence, string functon, Ability *ability):
	//		Card{name}, cost(cost), changeAttack(changeAttack), changeDefence(changeDefence), function(function) triggeredAbility{ability} {}
	else if (name == "Giant Strength") {
		const string enchantName = "Giant Strength";
		const string abilityName = "Enchanted minion gains +2/+2";
		Ability * actAb = new ActivatedAbility(abilityName);
		Ability * trigAb = nullptr;
		// const string function = "+";
		// int changeAtk = 2;
		// int changeDef = 2;
		Enchantment * myEnchant = new Enchantment(enchantName, 1,/* changeAtk,
				changeDef, function,*/actAb, trigAb);
		return myEnchant;
	} else if (name == "Enrage") {
		const string enchantName = "Enrage";
		const string abilityName = "Enchanted minion gains +2/+2";
		Ability * actAb = new ActivatedAbility(abilityName);
		Ability * trigAb = nullptr;
		// const string function = "*";
		// int changeAtk = 2;
		// int changeDef = 2;
		Enchantment * myEnchant = new Enchantment(enchantName, 2,/* changeAtk,
				changeDef, function,*/actAb, trigAb);
		return myEnchant;
	} else if (name == "Haste") {
		const string enchantName = "Haste";
		const string abilityName = "Enchanted minion gains +1 action each turn";
		Ability * actAb = nullptr;
		Ability * trigAb = new TriggeredAbility(abilityName);
		// const string function = "";
		// int changeAtk = 0;
		// int changeDef = 0;
		Enchantment * myEnchant = new Enchantment(enchantName, 1,/* changeAtk,
				changeDef, function,*/actAb, trigAb);
		return myEnchant;
	} else if (name == "Magic Fatigue") {
		const string enchantName = "Magic Fatigue";
		const string abilityName = "Enchanted minion’s activated ability costs 2 more";
		Ability * actAb = new ActivatedAbility(abilityName);
		Ability * trigAb = nullptr;
		// const string function = "";
		// int changeAtk = 0;
		// int changeDef = 0;
		Enchantment * myEnchant = new Enchantment(enchantName, 0,/* changeAtk,
				changeDef, function,*/actAb, trigAb);
		return myEnchant;
	} else if (name == "Silence") {
		const string enchantName = "Silence";
		const string abilityName = "Enchanted minion cannot use abilities";
		Ability * trigAb = new Ability(abilityName);
		Ability * actAb = nullptr;
		// const string function = "";
		// int changeAtk = 0;
		// int changeDef = 0;
		Enchantment * myEnchant = new Enchantment(enchantName, 1,/* changeAtk,
				changeDef, function,*/actAb, trigAb);
		return myEnchant;
	}
	
	// Ritual Cards goes here:
	//Ritual::Ritual(const string &name, int cost, int charge, int activationCost, Ability *ability):
	//		Card{name}, cost(cost) charge(charge), activationCost(activationCost), triggeredAbility{ability} {}
	else if (name == "Dark Ritual") {
		const string ritualName = "Dark Ritual";
		const string abilityName = "At the start of your turn, gain 1 magic";
		Ability * trigAb = new TriggeredAbility(abilityName);
		int charge = 5;
		int activateCost = 1;
		Ritual * myRitual = new Ritual(ritualName, 0, charge, activateCost,
				trigAb);
		return myRitual;
	} else if (name == "Aura of Power") {
		const string ritualName = "Aura of Power";
		const string abilityName = "Whenever a minion enters play under your control, it gains +1/+1";
		Ability * trigAb = new TriggeredAbility(abilityName);
		int charge = 4;
		int activateCost = 1;
		Ritual * myRitual = new Ritual(ritualName, 1, charge, activateCost,
				trigAb);
		return myRitual;
	} else if (name == "Standstill") {
		const string ritualName = "Standstill";
		const string abilityName = "Whenever a minion enters play, destroy it";
		Ability * trigAb = new TriggeredAbility(abilityName);
		int charge = 4;
		int activateCost = 2;
		Ritual * myRitual = new Ritual(ritualName, 3, charge, activateCost,
				trigAb);
		return myRitual;
	}
	//Card * newCard = new Card("Test");
	//return newCard;
	if(DBG) cout << "gets here" << endl;
	return nullptr;
}

// Shuffles the deck using the fisher Yates shuffle
void Deck::shuffle() {
	for (int i = size - 1; i > 0; i--) {
		int randomNum = rand() % (i + 1);
		Card* swap = cardList[i];
		cardList[i] = cardList[randomNum];
		cardList[randomNum] = swap;
	}
}

Deck::~Deck() {
}

//****************ABSTRACK DECK FUNCTIONS*************************

AbstractDeck::AbstractDeck(int size, int maxSize) :
		size { size }, maxSize{maxSize} {
}

AbstractDeck::~AbstractDeck() {
	for (auto& x : cardList) {
		if(DBG) cout << "Enter AbDeck Dtor for " << x->getName() << endl;
		delete x;
	}
}

// returns the card on the top of the deck and removes it from the deck
Card* AbstractDeck::getTopCard() {
	Card *temp = cardList.back();
	cardList.pop_back();
	return temp;
}

// returns ith card on the list 
Card* AbstractDeck::getIth(int i) {
	return cardList[i - 1];
}

// removes the ith card from the list
void AbstractDeck::remove(int i) {
	if(DBG) cout << "REMOVING " << cardList[i-1]->getName() << endl;
	cardList.erase(cardList.begin() + (i - 1));
}

//deletes the card from the list
void AbstractDeck::deleteCard(int i) {
	Card *temp = cardList[i];
	remove(i);
	delete temp;
}

// adds the card to the list
bool AbstractDeck::add(Card* card) {
	if(DBG) cout << "ENTER add for : ";
	if (cardList.size() < maxSize) {
		size++;
		cout<<card->getName()<<endl;
		cardList.emplace_back(card);
		if(DBG) cout << "Emplace Back working " << endl;
		return true;
	}
	return false;
}

// returns true if the list is empty
bool AbstractDeck::isEmpty() {
	return cardList.empty();
}

void AbstractDeck::addMinion(Card *card) {}

// shows the list on stdout
void AbstractDeck::show() {
	cout<<"Enter show function"<<endl;
	for(auto &x: cardList) {
		cout<<x->getName()<<endl;
	}
}

int AbstractDeck::numOfCards() {
	return cardList.size();
}

//****************HAND FUNCTIONS******************************

// Hand ctor
Hand::Hand(Deck *deck) :
		AbstractDeck { 0, 5 } {
	size = 0;
	cout<<"constructing Hand"<<endl;
	for(int i = 0; i < 5; i++) {
		cout<<"adding card "<<endl;
		add(deck->getTopCard());	
	}
}

//dtor for Hand
Hand::~Hand() {
}

//****************SLOTS FUNCTIONS******************************

// Slot ctor
Slot::Slot() :
		AbstractDeck { 0, 5 } {
	size = 0;
}

// void Slot::add(Card *card, int i) {
//	getIth(i)->addEnchantment(card);
// }

//dtor for Slot
Slot::~Slot() {
}


//changes the attack and defence of cards
void Slot::changeValOfCards(int attack, int defence){
	for(auto &b : cardList){
		b->changeAttack(attack);
		b->changeDefence(defence);
	}
}

void Slot::performStartTrigger(Player *p1, Player *p2) {
	for(auto &b : cardList){
		if(DBG) cout << "Setting Action to 1 for :" << b->getName() << endl;
		b->setActionTo1();
		b->performTriggeredAbility("startTurn", -1, nullptr, p1, p2);
	}
}

void Slot::performEndTrigger(Player *p1, Player *p2) {
	for(auto &b : cardList){
		b->performTriggeredAbility("endTurn", -1, nullptr, p1, p2);
	}
}
void Slot::performMinionEnter(Minion *minion, Player *p1, Player *p2) {
	if(DBG) cout << "Enter This fucking function " << cardList.size() << endl;
	try {
	for(int i = 0; i < cardList.size(); i++) {
		if(DBG) cout << "Entered in minionEnter loop inside Slot";
		dynamic_cast<Minion*>(cardList[i])->performTriggeredAbility("minionEnter", -1, minion, p1, p2);
	}
	} catch(const std::runtime_error& re)
{
    // speciffic handling for runtime_error
    std::cout << "Runtime error: " << re.what() << std::endl;
}
catch(const std::exception& ex)
{
    // speciffic handling for all exceptions extending std::exception, except
    // std::runtime_error which is handled explicitly
    std::cout << "Error occurred: " << ex.what() << std::endl;
}
catch(...)
{
    // catch any other errors (that we have no information about)
    std::cout << "Unknown failure occurred. Possible memory corruption" << std::endl;
}
}

void Slot::performMinionLeave(Minion *minion, Player *p1, Player *p2) {
	for(auto &b : cardList){
		b->performTriggeredAbility("minionLeave", -1, minion, p1, p2);
	}
}

void Slot::addMinion(Card *minion) {
    cardList.emplace_back(minion);
}


//****************GRAVEYARD FUNCTIONS*************************

// Graveyard ctor
Graveyard::Graveyard() :
		AbstractDeck(0, 30) {
}

//dtor for Graveyard
Graveyard::~Graveyard() {
}

void Graveyard::popTop() {
	cardList.pop_back();
}


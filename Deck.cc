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

using namespace std;

// Creates a new deck object and fills it with cards from the .deck file as specified

Deck::Deck(istream deckList) :AbstractDeck{0} {
	string currentCardName;
	int deckSize = 0;

	// Adds all the cards in the .deck file to the deck list
	while (deckList) {
		getline(deckList, currentCardName);
		cardList.push_back(createCard(currentCardName));
		deckSize++;
	}

	// sets the deck Size to number of cards added above
	size = deckSize;
}

// Creates a new card specific to the name of the card given
Card* Deck::createCard(string name) {

	// For All Spell Cards
	// All Spell Cards are initiated in the format: new Spell (string name, int magicCost, Ability ability)
	if (name == "Banish") {
		const string abilityName = "Destroy target minion or ritual";
		const string spellName = "Banish";
		Ability * banishAb = new Ability(abilityName);
		Spells * banish = new Spells(spellName, 2, banishAb);
		return banish;
	} else if (name == "Unsummon") {
		const string abilityName = "Return target minion to its owner’s hand";
		;
		const string spellName = "Unsummon";
		Ability * unsummonAb = new Ability(spellName);
		Spells * unsummon = new Spells(abilityName, 1, unsummonAb);
		return unsummon;
	} else if (name == "Recharge") {
		const string abilityName = "Your ritual gains 3 charges";
		const string spellName = "Recharge";
		Ability * rechargeAb = new Ability(abilityName);
		Spells * recharge = new Spells(spellName, 1, rechargeAb);
		return recharge;
	} else if (name == "Disenchant") {
		const string abilityName =
				"Destroy the top enchantment on target minion";
		const string spellName = "Disenchant";
		Ability * disenchantAb = new Ability(abilityName);
		Spells * disenchant = new Spells(spellName, 1, disenchantAb);
		return disenchant;
	} else if (name == "Raise Dead") {
		const string abilityName =
				"Resurrect the top minion in your graveyard and set its defence to 1";
		const string spellName = "Raise Dead";
		Ability * raiseDeadAb = new Ability(abilityName);
		Spells * raiseDead = new Spells(spellName, 1, raiseDeadAb);
		return raiseDead;
	} else if (name == "Blizzard") {
		const string abilityName = "Deal 2 damage to all minions";
		const string spellName = "Blizzard";
		Ability * BlizzardAb = new Ability(abilityName);
		Spells * Blizzard = new Spells(spellName, 3, BlizzardAb);
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
		Ability * newActAb = nullptr;
		Minions * myMinion = new Minions(minionName, 1, 1, 0, actAb, trigAb,
				newActAb);
		return myMinion;
	} else if (name == "Earth Elemental") {
		const string minionName = "Earth Elemental";
		Ability * actAb = nullptr;
		Ability * trigAb = nullptr;
		Ability * newActAb = nullptr;
		Minions * myMinion = new Minions(minionName, 4, 4, 3, actAb, trigAb,
				newActAb);
		return myMinion;
	} else if (name == "Bone Golem") {
		const string minionName = "Bone Golem";
		const string abilityName = "Gain +1/+1 whenever a minion leaves play.";
		Ability * actAb = nullptr;
		Ability * trigAb = new Ability(abilityName);
		Ability * newActAb = nullptr;
		Minions * myMinion = new Minions(minionName, 1, 3, 2, actAb, trigAb,
				newActAb);
		return myMinion;
	} else if (name == "Fire Elemental") {
		const string minionName = "Fire Elemental";
		const string abilityName =
				"Whenever an opponent’s minion enters play, deal 1 damage to it.";
		Ability * actAb = nullptr;
		Ability * trigAb = new Ability(abilityName);
		Ability * newActAb = nullptr;
		Minions * myMinion = new Minions(minionName, 2, 2, 2, actAb, trigAb,
				newActAb);
		return myMinion;
	} else if (name == "Potion Seller") {
		const string minionName = "Potion Seller";
		const string abilityName =
				"At the end of your turn, all your minions gain +0/+1.";
		Ability * actAb = nullptr;
		Ability * trigAb = new Ability(abilityName);
		Ability * newActAb = nullptr;
		Minions * myMinion = new Minions(minionName, 1, 3, 2, actAb, trigAb,
				newActAb);
		return myMinion;

		// need to update a cost for activating ability when ability class done
	} else if (name == "Novice Pyromancer") {
		const string minionName = "Novice Pyromancer";
		const string abilityName = "Deal 1 damage to target minion";
		Ability * actAb = new Ability(abilityName);
		Ability * trigAb = nullptr;
		Ability * newActAb = nullptr;
		Minions * myMinion = new Minions(minionName, 1, 3, 2, actAb, trigAb,
				newActAb);
		return myMinion;
	} else if (name == "Apprentice Summoner") {
		const string minionName = "Apprentice Summoner";
		const string abilityName = "Summon a 1/1 air elemental";
		Ability * actAb = new Ability(abilityName);
		Ability * trigAb = nullptr;
		Ability * newActAb = nullptr;
		Minions * myMinion = new Minions(minionName, 1, 1, 1, actAb, trigAb,
				newActAb);
		return myMinion;
	} else if (name == "Master Summoner") {
		const string minionName = "Master Summoner";
		const string abilityName = "Summon up to three 1/1 air elementals";
		Ability * actAb = new Ability(abilityName);
		Ability * trigAb = nullptr;
		Ability * newActAb = nullptr;
		Minions * myMinion = new Minions(minionName, 2, 3, 3, actAb, trigAb,
				newActAb);
		return myMinion;
	}

	// Enchantment Cards goes here:

	// Ritual Cards goes here:

	else{
	Card * newCard = new Card();
	return newCard;
	}
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

//****************ABSTRACK DECK FUNCTIONS*************************

AbstractDeck::AbstractDeck(int size) : size{size} {
	cardList = nullptr;
}

AbstractDeck::~AbstractDeck() {
	for (auto& x: cardList) {
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
Card* AbstractDeck::getIthCard(int i) {
	return cardList[i - 1];
}

// removes the ith card from the list
void AbstractDeck::removeCard(int i) {
	cardList.erase(cardList.begin() + (i - 1));
}

//deletes the card from the list
void AbstractDeck::deleteCard(int i) {
	Card *temp = cardList[i];
	removeCard(i);
	delete temp;
}

// adds the card to the list
void AbstractDeck::add(Card* card) {
	cardList.push_back(card);
	//cardList.emplace_back(card);
}

bool AbstractDeck::isEmpty() {
	return cardList.empty();
}

//****************HAND FUNCTIONS******************************

// Hand ctor
Hand::Hand(Deck *deck) : AbstractDeck{0} {
	size = 5;
	for(int i = 0; i < 5; i++) {
		add(deck->getTopCard());	
	}
}


//****************SLOTS FUNCTIONS******************************

// Slot ctor
Slot::Slot() : AbstractDeck{0} {
	size = 0;
	cardList = nullptr;
} 

void Slot::add(Card *card, int i) {
	getIthCard(i)->addEnchantment(card);
}


//****************GRAVEYARD FUNCTIONS*************************

// Graveyard ctor
Graveyard::Graveyard() : AbstractDeck(0) {
	cardList = nullptr;
}

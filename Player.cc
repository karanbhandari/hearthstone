#include <string>
#include <sstream>
#include <iostream>
#include <memory>

#include "Deck.h"
#include "Board.h"
#include "Card.h"
#include "Minion.h"
#include "Spells.h"
#include "Enchantment.h"
#include "Ritual.h"

#define dbg false
using namespace std;

// ctor for Player
Player::Player(string myName, istream *in) : 
		name{myName}, magic{3}, life{20} {
	deck = new Deck(*in);
	deck->shuffle();
	hand = new Hand{deck};
	slot = new Slot();
	graveyard = new Graveyard();
	ritual = nullptr;
}

// dtor for players
Player::~Player() {
	delete deck;
	deck = nullptr;
	delete hand;
	hand = nullptr;
	delete slot;
	hand = nullptr;
	delete graveyard;
	graveyard = nullptr;
	delete ritual;
	ritual = nullptr;
}

// returns the magic available to the player
int Player::getMagic() {
	return magic;
}

// changes the value of the Magic of the player
void Player::changeMagic(int change) {
	magic += change;
}

// changes the value of the Magic of the player
void Player::changeLife(int change) {
	life += change;
}

//draw a card from the deck
void Player::draw() {
	if (!deck->isEmpty() && hand->numOfCards() < 5) 
		hand->add(deck->getTopCard());
	else 
		cout << "deck isEmpty or hand is fill" << endl;
}

//Perform the start of turn trigger
void Player::performStartTrigger(Player *activePlayer, Player *opponent) {
	magic++;
	draw();
	slot->performStartTrigger(activePlayer, opponent);
	if (ritual)
		ritual->performTriggeredAbility("startOfTurn", -1, nullptr, activePlayer, opponent);
}

// Performs the end of turn Triggers
void Player::performEndTrigger(Player *activePlayer, Player *opponent) {
	slot->performEndTrigger(activePlayer, opponent);
	if (ritual)
	ritual->performTriggeredAbility("endOfTurn", -1,  nullptr, activePlayer, opponent);
}

// Perform the minion enter trigger
void Player::performMinionEnter(Minion *minion, Player *activePlayer, Player *opponent) {
	if(dbg) cout << "Entered minion Enter Ability " << endl;
	slot->performMinionEnter(minion, activePlayer, opponent);
	if(dbg) cout << "Perform Enter works" << endl;
	if (ritual)
	ritual->performTriggeredAbility("minionEnter", -1, minion, activePlayer, opponent);
	if(dbg) cout << "Reaches to opponent now" << endl;
	opponent->slot->performMinionEnter(minion, activePlayer, opponent);
	if (opponent->ritual)
	opponent->ritual->performTriggeredAbility("minionEnter", -1, minion, activePlayer, opponent);
	if(dbg) cout << "Abilities Worked for Minion Enter" << endl;
}

// Perform the minion enter trigger
void Player::performMinionLeave(Minion *minion, Player *activePlayer, Player *opponent) {
	slot->performMinionLeave(minion, activePlayer, opponent);
	if (ritual)
	ritual->performTriggeredAbility("minionLeave" , -1, minion, activePlayer, opponent);
	opponent->slot->performMinionLeave(minion, activePlayer, opponent);
	if (opponent->ritual)
	opponent->ritual->performTriggeredAbility("minionLeave", -1, minion, activePlayer, opponent);
}


// Discards ith card from the hand
void Player::discard(int i) {
	hand->deleteCard(i); 
	// TODO: add card leave play trigger here
}

// Attack the opponent player using the ith card
void Player::attack(int i, Player *opponent){
	dynamic_cast<Minion *>(slot->getIth(i))->attackOther(opponent);
}


// Attack the opposing minion
void Player::attack(int i, Player *opponent, int j, Player *activePlayer) {
	Minion *minion1 = dynamic_cast<Minion*>(slot->getIth(i));
	Minion *minion2 = dynamic_cast<Minion*>(opponent->slot->getIth(j));
	minion1->attackOther(minion2);
	minion2->attackOther(minion1);
	if (minion2->isDead()) {
		opponent->slot->remove(j);
		opponent->graveyard->add(minion2);
		performMinionLeave(minion2, activePlayer, opponent);
	} 
	if (minion1->isDead()) {
		slot->remove(i);
		graveyard->add(minion1);
		performMinionLeave(minion1, activePlayer, opponent);
	}
}

// add the ith card on the hand on the slots
void Player::play(int i, Player *activePlayer, Player *opponent) {
	Card *card1 = hand->getIth(i);
	if(getMagic() - card1->getCardCost() < 0) {
		cout << "Player " << name << " doesn't have enough magic to play " << card1->getName() << endl;
		cout << "Player only has " << getMagic() << endl;
		cout << "You need " << card1->getCardCost() << endl;
		return;
	} else if (dynamic_cast<Minion*>(card1)) {
		auto card = dynamic_cast<Minion*>(card1);
		if(dbg) cout << card->getName() << " str" <<  endl;
		if(slot->add(card1)) {
			slot->show();
			performMinionEnter(card, activePlayer, opponent);	
			hand->remove(i);
			changeMagic(card1->getCardCost() * -1);
		}	
	} else if (dynamic_cast<Spell*>(card1)) {
		auto card = dynamic_cast<Spell*>(card1);
		hand->remove(i);
		card->performActivatedAbility(-1, nullptr, activePlayer, opponent);
		card->performActivatedAbility2(-1, dynamic_cast<Ritual*>(ritual), activePlayer, opponent);
		delete card;
		changeMagic(card1->getCardCost() * -1);
	} else if (dynamic_cast<Ritual*>(card1)) {
		if(dbg) cout << "Enter Ritual cast" << endl;
		if (ritual) {
			delete ritual;
		}
		auto card = dynamic_cast<Ritual*>(card1);
		ritual = card;
		hand->remove(i);
		changeMagic(card1->getCardCost() * -1);
	} else if (dynamic_cast<Enchantment*>(card1)) {
		cout << "This is a wrong use of Enchantment, it should be played on a Minion" << endl;
	}
}

// play the ith card on the hand on the minion/ritual
void Player::play(int i, Player *p, int j, Player *activePlayer, Player *opponent) {
	Card *card1 = hand->getIth(i);
	if(getMagic() - card1->getCardCost() < 0) {
		cout << "Player " << name << " doesn't have enough magic to play " << card1->getName() << endl;
		return;
	}
	if (dynamic_cast<Minion*>(card1)) {
		cout << "This is a wrong use of Minion, it can't be played on a Minion" << endl;
	} else if (dynamic_cast<Spell*>(card1)) {
		auto card = dynamic_cast<Spell*>(card1);
		hand->remove(i);
		if(dbg) cout << "shit" << endl;
		if (j != 114)
			card->performActivatedAbility(j, dynamic_cast<Minion*>(p->hand->getIth(j)), activePlayer, opponent);
		else
			card->performActivatedAbility2(-1, dynamic_cast<Ritual*>(p->ritual), activePlayer, opponent);
		delete card;
		changeMagic(card1->getCardCost() * -1);
	} else if (dynamic_cast<Ritual*>(card1)) {
		cout << "This is a wrong use of Ritual, it should be played on a Minion" << endl;
	} else if (dynamic_cast<Enchantment*>(card1)) {
		auto card = dynamic_cast<Enchantment*>(card1);
		hand->remove(i);
		dynamic_cast<Minion*>(slot->getIth(j))->updateActivatedAbility(card);
		changeMagic(card1->getCardCost() * -1);
	} 
}


// uses the activated ability
void Player::use(int i, Player *activePlayer, Player *opponent) {
	slot->getIth(i)->performActivatedAbility(-1, nullptr, activePlayer, opponent); //TODO: add support in cards @karan
}

// uses the activitaed ability on player p's 
void Player::use(int i, Player *p, int j, Player *activePlayer, Player *opponent) {
	dynamic_cast<Minion*>(slot->getIth(i))->performActivatedAbility(j, 
		dynamic_cast<Minion*>(p->slot->getIth(j)), activePlayer, opponent);
}

// returns the name of the Player
string Player::getName() {
	return name;
}

// returns true if the Player has life > 0
bool Player::isAlive() {
	return life > 0;
}

// updates the attack and defence of the whole slot
void Player::updateSlot(int attack, int defence) {
  slot->changeValOfCards(attack, defence);
}


// adds the card to the place
// Not needed anymore @Karan
void Player::addCard(string place, Card *card) {
	if (place == "Slot") {
		if(!slot->add(card))
			delete card;
	}
}

// removes a specific card form the slot
void Player::removeCard(int minionNum) {
 // slot->deleteCard(minionNum);
  Card *temp = slot->getIth(minionNum);
  slot->remove(minionNum);
  bool boolVal = graveyard->add(temp);
}

//displays the Hand of the player
void Player::showHand() {
	hand->show();
}

void Player::showDeck() {
	deck->show();
}

//the describe, hand and board command would take place in main would take place in main


void Player::returnMinionToHand(int minionNum, Minion *minion) {
  // check the card inside the slot and then give it back to the hand

  if(slot->numOfCards() >= 5){
    cout << "Cannot play this move since Hand is full." << endl;
    return;
  } else {
    Card *temp = slot->getIth(minionNum);
    slot->remove(minionNum);
    hand->add(temp);
  }
}

// removes top enchantment from the target minion
void Player::destroyTopEnchantment(int minionNum) {
  Card *target = slot->getIth(minionNum);
  target->popTopEnchantment();
}

// raises minion from the graveyard to the slot
void Player::raiseTheDead() {
  if(slot->numOfCards() >= 5) {
    cout << "Cannot use this card since the board is full" << endl;
  } else if(graveyard->isEmpty()){
    cout << "cannot use this card since there is no Minion in Grave" << endl;
  } else { //TODO: add check for null from graveyard
    Card *temp = graveyard->getTopCard();
    if(slot->add(temp)) {
    	dynamic_cast<Minion*>(temp)->reInitializeDefence(1);
    } 
 }
}

void Player::updateRitual(int charge) {
  ritual->updateCharge(charge);
}

int Player::powerOfRitual() {
  return ritual->power();
}

void Player::removeRitual() {
  delete ritual;
  ritual = nullptr;
}


Hand* Player::getHand() {
	return hand;
}

Slot * Player::getSlot() {
	return slot;
}

Deck * Player::getDeck() {
	return deck;
}

Graveyard *Player::getGraveyard() {
	return graveyard;
}

Ritual* Player::getRitual() {
	if(ritual)
		return dynamic_cast<Ritual*>(ritual);
	if(dbg) cout << ritual << " Ritual address" << endl;
	return nullptr;
}

void Player::moveToGraveyard() {
	for(int i = 0; i < slot->numOfCards(); i++) {
		Minion * card = dynamic_cast<Minion*>(slot->getIth(i + 1));
		if(card->isDead()) {
			slot->remove(i+1);
			graveyard->add(card);
			i--;
		}
	}
}

void Player::deleteRitual() {
	delete dynamic_cast<Ritual*>(ritual);
	ritual = nullptr;
}

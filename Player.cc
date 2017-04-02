#include <string>
#include <sstream>
#include <iostream>

#include "Board.h"

using namespace std;

// ctor for Player
Player::Player(string myName, istream *in) : 
		name{myName}, magic{3}, life{20} {
	deck = new Deck(*in);
	hand = new Hand{deck};
	slot = new Slot();
	graveyard = new Graveyard();
}

// dtor for players
Player::~Player() {
	delete deck;
	delete hand;
	delete slot;
	delete graveyard;
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
	if (!deck->isEmpty()) 
		hand->add(deck->getTopCard());
	else 
		cout << "deck isEmpty" << endl;
}

//Perform the start of turn trigger
void Player::performStartTrigger(Player *activePlayer, Player *opponent) {
	slot->performStartTrigger(activePlayer, opponent);
	ritual->performTriggerAbility("startTurn", nullptr, activePlayer, opponent);
}

// Performs the end of turn Triggers
void Player::performEndTrigger(Player *activePlayer, Player *opponent) {
	slot->performEndTrigger(activePlayer, opponent);
	ritual->performTriggerAbility("endTurn", nullptr, activePlayer, opponent);
}

// Perform the minion enter trigger
void Player::performMinionEnter(Minion *minion, Player *activePlayer, Player *opponent) {
	slot->performMinionEnter(minion, activePlayer, opponent);
	ritual->performTriggerAbility("minionEnter", minion, activePlayer, opponent);
}

// Perform the minion enter trigger
void Player::performMinionLeave(Minion *minion, Player *activePlayer, Player *opponent) {
	slot->performMinionLeave(minion, activePlayer, opponent);
	ritual->performTriggerAbility("minionLeave" ,minion, activePlayer, opponent);
}


// Discards ith card from the hand
void Player::discard(int i) {
	hand->deleteCard(i); 
	// TODO: add card leave play trigger here
}

// Attack the opponent player using the ith card
void Player::attack(int i, Player *opponent){
	slot->getIth(i)->attack(opponent);
}


// Attack the opposing minion
void Player::attack(int i, Player *opponent, int j) {
	Minion *minion1 = slot->getIth(i);
	Minion *minion2 = opponent->slot->getIth(j)
	minion1->attack(minion2);
	minion2->attack(minion1);
	if (minion2->isDead()) {
		opponent->slot->remove(i);
		graveyard->add(minion2);
	} else if (minion1->isDead()) {
		slot->remove(i);
		graveyard->add(minion1);
	}
}

// add the ith card on the hand on the slots
void Player::play(int i, Player *activePlayer, Player *opponent) {
	Card *card1 = hand->getIth(i);
	if (dynamic_pointer_cast<Minion>(card1)) {
		if(slot->add(card1)) {
			slot->callMinionEnter(card1);	
		}				
	} else if (dynamic_pointer_cast<Spell>(card1)) {
		Spell *spell = hand->getIth(i);
		hand->remove(i);
		spell->performAbility(-1, nullptr, activePlayer, opponent);
		delete spell;
	} else if (dynamic_pointer_cast<Ritual>(card1)) {
		Ritual *ritual = hand->getIth(i);
		hand->remove(i);
	} else if (dynamic_pointer_cast<Enchantment>(card1)) {
		cout << "This is a wrong use of Enchantment, it should be played on a Minion" << endl;
	}
	// TODO: add enter play trigger call here
	hand->getIth(i)->addToBoard(ritual, nullptr, slot);
	hand->remove(i);
}

// play the ith card on the hand on the minion/ritual
void Player::play(int i, Player *p, int j, Player *activePlayer, Player *opponent) {
	Card *card1 = hand->getIth(i);
	if (dynamic_pointer_cast<Minion>(card1)) {
		cout << "This is a wrong use of Minion, it can't be played on a Minion" << endl;
	} else if (dynamic_pointer_cast<Spell>(card1)) {
		Spell *spell = hand->getIth(i);
		hand->remove(i);
		spell->performAbility(j, hand->getIth(j), activePlayer, opponent);
	} else if (dynamic_pointer_cast<Ritual>(card1)) {
		cout << "This is a wrong use of Ritual, it should be played on a Minion" << endl;
	} else if (dynamic_pointer_cast<Enchantment>(card1)) {
		Enchantment *enchantment = hand->getIth(i);
		hand->remove(i);
		hand->getIth(j)->updateActivatedAbility(enchantment);
	} 
}


// uses the activated ability
void Player::use(int i, Player *activePlayer, Player *opponent) {
	slot->getIth(i)->performActivatedAbility(-1, nullptr, activePlayer, opponent); //TODO: add support in cards @karan
}

// uses the activitaed ability on player p's 
void Player::use(int i, int j, Player *activePlayer, Player *opponent) {
	slot->getIth(i)->performActivatedAbility(j, p->slot->getIth(j), opponent);
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
void Player::addCard(string place, Minion *card) {
	if (place == "Slot") {
		slot->add(card); // TODO : add fucntion should check for maxSize
	}
}

// removes a specific card form the slot
void Player::removeCard(int minionNum) {
  slot->remove(minionNum);
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
void Player::detroyTopEnchantment(int minionNum) {
  Card *target = slot->getIth(minionNum);
  target->popTopEnchantment();
}

// raises minion from the graveyard to the slot
void Player::raiseTheDead() {
  if(slot->numOfCards >= 5) {
    cout << "Cannot use this card since the board is full" << endl;
  } else if(graveyard->isEmpty()){
    cout << "cannot use this card since there is no Minion in Grave" << endl;
  } else {
    Card *temp = graveyard->getTopCard();
    graveyard->popTop();
    temp->reInitializeDefence(1);
    slot->add(temp);
  }
}

void updateRitual(int charge) {
  ritual->updateCharge(charge)
}

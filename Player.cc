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

// Perform the start of turn trigger
//void Player::performStartTrigger() {
//	slot->performStartTrigger();
//}

// Performs the end of turn Triggers
//void Player::performEndTrigger() {
//	slot->performEndTrigger();
//}


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
	slot->getIth(i)->attack(opponent->slot->getIth(j));
	opponent->slot->getIth(j)->attack(slot->getIth(j));
}

// add the ith card on the hand on the slots
void Player::play(int i) {
	// TODO: add enter play trigger call here
	hand->getIth(i)->addToBoard(ritual, nullptr, slot);
	hand->remove(i);
}

// play the ith card on the hand on the minion/ritual
void Player::play(int i, Player *p, int j) {
	// TODO: add enter play trigger call in addToBoard
	hand->getIth(i)->addToBoard(ritual, p->hand->getIth(j), slot);
	hand->remove(i);
}


// uses the activated ability
void Player::use(int i) {
//	slot->getIth(i)->performActivatedAbility();
}

// uses the activitaed ability on player p's 
void Player::use(int i, Player *p, int j) {
//	slot->getIth(i)->performActivatedAbility(p->slot->getIth(j));
}

// returns the name of the Player
string Player::getName() {
	return name;
}

// returns true if the Player has life > 0
bool Player::isAlive() {
	return life > 0;
}


//the describe, hand and board command would take place in main would take place in main




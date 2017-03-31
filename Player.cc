#include <string>
#include <sstream>
#include <iostream>
#include "Player.h"

using namespace std;

// ctor for Player
Player::Player(string& myName) : 
		name{myName}, magic{3}, life{20} {
	deck = new Deck();
	hand = new Hand{deck};
	slots = new Slots();
	graveyard = new graveyard();
}

// dtor for players
Player::~Player() {
	delete deck;
	delete hand;
	delete slots;
	delete graveyard;
}

// returns the magic available to the player
int Player::getMagic() {
	return magic;
}

// changed the value of the Magic of the player
void Player::changeMagic(int change) {
	magic += change;
}

//draw a card from the deck
void Player::draw() {
	if (!deck->isEmpty()) 
		hand->add(deck->getTopCard);
	else 
		cout << "deck isEmpty" << endl;
}

// Perform the start of turn trigger
void Player::performStartTrigger() {
	slots->performStartTrigger();
}

// Performs the end of turn Triggers
void Player::performEndTrigger() {
	slots->performEndTrigger();
}


// Discards ith card from the hand
void Player::discard(int i) {
	hand->deleteCard(i); // this remove function should perform card leave play trigger
}

// Attack the opponent player using the ith card
void Player::attack(int i, Player *opponent){
	slot->getIth(int i)->attack(opponent);
}


// Attack the opposing minion
void Player::attack(int i, Player *opponent, int j) {
	slot->getIth(int i)->attack(opponent->slot->getIth(int j));
	opponent->slot->getIth(int j)->attack(slot->getIth(int j));
}

// add the ith card on the hand on the slots
void Player::play(int i) {
	// TODO: add enter play trigger call here
	slot->add(hand->getIth(int i));
	hand->remove(int i)
}

// play the ith card on the hand on the minion/ritual
void Player::play(int i, Player *p, int j) {
	// TODO: add enter play trigger call here
	if (j >= 1 && j <= 5) { // play on the minion
		p->slot->add(hand->getIth(int i), j);
	}
}


// uses the activated ability
void Player::use(int i) {
	slot->getIth(i)->performActivatedAbility();
}

// uses the activitaed ability on player p's 
void Player::use(int i, Player *p, int j) {
	slot->getIth(i)->performActivatedAbility(p->slot->getIth(j));
}


//the describe, hand and board command would take place in main would take place in main




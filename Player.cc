#include <string>
#include <sstream>
#include <iostream>
#include "Player.h"

using namespace std;

// ctor for Player
Player::Player(string& myName) : 
		name{myName}, magic{3}, life{20} {
	deck = new Deck();
	hand = new Hand(deck);
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
	hand->remove(i); // this remove function should perform card leave play trigger
}

// Attack the opponent player using the ith card
void attack(int i, Player *opponent){
	slot->getIth(int i)->attack(opponent);
}


// Attack the opposing minion
void attack(int i, Player *opponent, int j) {
	slot->getIth(int i)->attack(opponent->slot->getIth(int j));
}


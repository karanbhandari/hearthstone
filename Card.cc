#include <iostream>
#include <string>
#include "Card.h"
#include "Player.h"

using namespace std;

//Card::Card() {};

// Creates a new card specific to the name of the card given
Card::Card(string name) : name{name} {
}

void Card::changeAttack(int attack) {}

void Card::changeDefence(int defence) {}

string Card::getName() {
	return name;
}

void Card::addToBoard(Card *ritualSlot, Card *minion, Slot *slot) {}

void Card::attack(Card *minion){}
void Card::attack(Player *player){}
void Card::popTopEnchantment() {};
void Card::reInitializeDefence(int val) {};  
void updateCharge(int val) {};
Card::~Card() {}

#include <iostream>
#include <string>
#include "Card.h"
#include "Player.h"

using namespace std;

//Card::Card() {};

// Creates a new card specific to the name of the card given
Card::Card(string name, int cost) : name{name}, cardCost{cost} {
	Minion * minion = dynamic_cast<Minion*>(*this);
	Enchantment *enchantment = dynamic_cast<Enchantment*>(*this);
	Ritual *ritual = dynamic_cast<Ritual*>(*this);
	Spell *spell = dynamic_cast<Spell*>(*this);
	delete minion;
	delete enchantment;
	delete ritual;
	delete spell;
}

void Card::changeAttack(int attack) {}

void Card::changeDefence(int defence) {}

string Card::getName() {
	return name;
}

void Card::setActionTo1() {}

int Card::power() {}

void Card::addToBoard(Card *ritualSlot, Card *minion, Slot *slot) {}

void Card::attack(Card *minion){}
void Card::attack(Player *player){}
void Card::popTopEnchantment() {};
//void Card::reInitializeDefence(int val) {};  
void Card::performActivatedAbility(int minionNum, Minion *minion, Player *p1, Player *p2) {}
void Card::performTriggeredAbility(std::string what, int minionNum, Minion *minion, Player *p1, Player *p2) {}
void Card::updateCharge(int val) {};
Card::~Card() {}

int Card::getCardCost() {
	return cardCost;
}

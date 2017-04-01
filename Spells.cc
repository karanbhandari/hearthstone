/*
 * Spells.cc
 *
 *  Created on: Mar 23, 2017
 *      Author: Acer User
 */

#include <string>
#include <sstream>
#include "Spells.h"
#include "Player.h"
#include "Ability.h"

using namespace std;

Spells::Spells(const string &name, int cost, Ability *myAbility) :
		name(name), cost(cost), spellAbility(myAbility) {
}

Spells::~Spells(){
	delete spellAbility;
	spellAbility = nullptr;
}

//bool Spells::canActivate() {
	//return spellPlayer->getMagic() >= cost;
//}

void Spells::activate() {
	//if (canActivate()) {
		//spellPlayer->changeMagic(-(cost));
		spellAbility->performAbility();
		moveToGrave();
	//} else
	//	throw "not enough mana";
}

void Spells::moveToGrave() {
	// move to graveyard
}

void Spells::addToBoard(Card *ritualSlot, Card *MinionCardForEnch, Slot *slot) {
	// Performs ability and then deletes the card.. See TODO in this file 
	// TODO: perform ability
	delete this;
}

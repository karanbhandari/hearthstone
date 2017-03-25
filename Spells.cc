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

Spells::Spells(const string& name, int cost, Ability *myAbility,
		Player *myPlayer) :
		name(name), cost(cost), spellAbility(myAbility), spellPlayer(myPlayer) {
}

bool Spells::canActivate() {
	return spellPlayer->getMagic() >= cost;
}

void Spells::activate() {
	if (canActivate()) {
		spellPlayer->changeMana(-(cost));
		spellAbility->performAbility();
		moveToGrave();
	} else
		throw "not enough mana";
}

void Spells::moveToGrave() {
	// move to graveyard
}

/*
 * Spell.cc
 *
 *  Created on: Mar 23, 2017
 *      Author: Acer User
 */
#include <iostream>
#include <string>
#include <sstream>
#include "Spells.h"
#include "Player.h"
#include "Ability.h"
#include "Minion.h"
#include "Ritual.h"

using namespace std;

Spell::Spell(const string name, int cost, Ability *myAbility) :
		Card{name, cost}, spellAbility(myAbility) {
}

Spell::~Spell(){
	delete spellAbility;
	spellAbility = nullptr;
}

//bool Spell::canActivate() {
	//return spellPlayer->getMagic() >= cost;
//}


void Spell::moveToGrave() {
	// move to graveyard
}

Ability* Spell::getAbility() {
	return spellAbility;
}

void Spell::performActivatedAbility(int minionNum, Minion *minion, Player *p1, Player *p2) {
	spellAbility->performAbility("", minionNum, minion, p1, p2);
}

void Spell::performActivatedAbility2(int minionNum, Ritual *ritual, Player *p1, Player *p2) {
	spellAbility->performAbility("", minionNum, ritual, p1, p2);
}


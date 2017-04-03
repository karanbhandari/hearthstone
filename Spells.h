/*
 * spells.h
 *
 *  Created on: Mar 23, 2017
 *      Author: Acer User
 */
#ifndef __SPELLS_H__
#define __SPELLS_H__

#include <string>
#include <sstream>
#include <iostream>
#include "Card.h"

class Slot;
class Ability;

class Spell: public Card {
	int cost;
	Ability *spellAbility; // link to an ability to activate
	//Player *spellPlayer; // What is this for ??? @Karan

public:
	Spell (const std::string name, int cost, Ability * myAbility);
	~Spell();
	//bool canActivate ();
	void performActivatedAbility(int minionNum, Minion *minion, Player *p1, Player *p2) override;
	void moveToGrave ();
};

#endif

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
	Spell (const std::string &name, int cost, Ability * myAbility);
	~Spell();
	//bool canActivate ();
	void activate ();
	void moveToGrave ();
	void addToBoard(Card *ritualSlot, Card *MinionCardForEnch, Slot *slot) override;
};

#endif

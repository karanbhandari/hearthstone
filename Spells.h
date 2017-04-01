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
#include "Player.h"
#include "Ability.h"
#include "Cards.h"

class Spells: public Cards {
	int cost;
	std::string name;
	Ability *spellAbility; // link to an ability to activate
	//Player *spellPlayer; // What is this for ??? @Karan

public:
	Spells (const std::string &name, int cost, Ability * myAbility);
	~Spell();
	//bool canActivate ();
	void activate ();
	void moveToGrave ();
	void addToBoard(Card *ritualSlot, Card *MinionCardForEnch, Slot *slot) override;
};

#endif

/*
 * spells.h
 *
 *  Created on: Mar 23, 2017
 *      Author: Acer User
 */

#include <string>
#include <sstream>
#include <iostream>
#include "Player.h"
#include "Ability.h"

using namespace std;

class Spells {
	int cost;
	string name;
	string description; // I need to implement something to add in description
	Ability *spellAbility; // link to an ability to activate
	Player *spellPlayer;

public:
	Spells (const string& name, int cost, Ability * myAbility, Player * myPlayer);
	//~Spell();
	bool canActivate ();
	void activate ();
	void moveToGrave ();
};

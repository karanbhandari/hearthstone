/*
 * Ability.h
 *
 *  Created on: Mar 23, 2017
 *      Author: Acer User
 */
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
#ifndef ABILITY_H_
#define ABILITY_H_

class Ability {
	string name;

public:
	Ability (string& nameOfAbility);
	void performAbility ();
};


#endif /* ABILITY_H_ */

/*
 * Ability.cc
 *
 *  Created on: Mar 23, 2017
 *      Author: Acer User
 */
#include "Ability.h"
#include <string>
#include <iostream>


using namespace std;

Ability::Ability(const string & name) {
	this->name = name;
}
void Ability::performAbility() {
	cout << "Ability Activated! \n";
}


/*
 * Ability.h
 *
 *  Created on: Mar 23, 2017
 *      Author: Acer User
 */
#ifndef __ABILITY_H__
#define __ABILITY_H__

#include <string>
#include <sstream>
#include <iostream>

class Ability {
	std::string name;

public:
	Ability (const std::string& nameOfAbility);
	void performAbility ();
};


#endif /* ABILITY_H_ */

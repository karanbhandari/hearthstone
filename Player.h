/*
 * Player.h
 *
 *  Created on: Mar 23, 2017
 *      Author: Acer User
 */
#ifndef __PLAYER_H_
#define __PLAYER_H_

#include <string>
#include <sstream>
#include <iostream>

class Player {
	std::string name;
	int magic;
	int life;

public:
	Player (std::string& myName);
	int getMagic ();
	void changeMana (int change);
};




#endif /* PLAYER_H_ */

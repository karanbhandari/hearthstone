/*
 * Player.h
 *
 *  Created on: Mar 23, 2017
 *      Author: Acer User
 */

#include <string>
#include <sstream>
#include <iostream>

using namespace std;
#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
	string name;
	int magic;
	int life;

public:
	Player (string& myName);
	int getMagic ();
	void changeMana (int change);
};




#endif /* PLAYER_H_ */

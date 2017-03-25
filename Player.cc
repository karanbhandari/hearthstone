/*
 * Player.cc
 *
 *  Created on: Mar 23, 2017
 *      Author: Acer User
 */
#include <string>
#include <sstream>
#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(string& myName) :
		name(myName), magic(0), life (20) {
}

int Player::getMagic() {
	return magic;
}

void Player::changeMana(int change) {
	magic += change;
}


#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include <iostream>

#include "Deck.h"
#include "Cards.h"


class Player {
	std::string name;
	int magic;
	int life;
	Hand *hand;
	Slot *slot;
	Deck *deck;
	Graveyard *graveyard;
	Card *ritual;
public:
	Player(std::string& myName);
	~Player();
	int getMagic();
	void changeMagic(int change);
	void changeLife(int change);
	void draw();
	void performStartTrigger();
	void perfromEndTrigger();
	void discard(int i);
	void attack(int i, Player* opponent);
	void attack(int i, Player* opponent, int j);
	void play(int i);
	void play(int i, Player *p, int j);
	void use(int i);
	void use(int i, Player *p, int j);
	std::string getName();
	bool isAlive();
};


#endif

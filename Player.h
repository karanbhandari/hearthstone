#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include <iostream>

class Player {
	std::string name;
	int magic;
	int life;
	Hand *hand;
	Slot *slot;
	Deck *deck;
	Graveyard *graveyard;
public:
	Player(string& myName);
	~Player();
	int getMagic();
	void changeMagic(int change);
	void draw();
	void performStartTrigger();
	void perfromEndTrigger();
	void discard(int i);
	void attack(int i, Player* opponent);
	void attack(int i, Player* opponent, int j);
};


#endif

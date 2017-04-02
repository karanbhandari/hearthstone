#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include <iostream>
#include <sstream>

#include "Deck.h"
#include "Card.h"

class Minion;

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
	Player(std::string myName, std::istream *in);
	~Player();
	int getMagic();
	void changeMagic(int change);
	void changeLife(int change);
	void draw();
	void performStartTrigger(Player *activePlayer, Player *opponent);
	void perfromEndTrigger(Player *activePlayer, Player *opponent);
	void performMinionEnter(Minion *minion, Player *activePlayer, Player *opponent);
	void performMinionLeave(Minion *minion, Player *activePlayer, Player *opponent);
	void discard(int i);
	void attack(int i, Player* opponent);
	void attack(int i, Player* opponent, int j);
	void play(int i);
	void play(int i, Player *p, int j);
	void use(int i);
	void use(int i, Player *p, int j);
	std::string getName();
	bool isAlive();
	void updateSlot(int attack, int defence);
	// Not needed anymore @Karan
  // void addCard(std::string place, Minion *card);
 	void removeCard(int minionNum);
	void showHand();
	void showDeck();
 	void returnMinionToHand(int minionNum, Minion *minion);
 	void destroyTopEnchantment(int minionNum);
 	void raiseTheDead();
 	void updateRitual(int charge);
};


#endif

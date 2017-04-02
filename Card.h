#ifndef _CARD_H_
#define _CARD_H_

#include <string>
#include <sstream>
#include <iostream>
#include "Deck.h"

class Player;

// this is an abstract cards class that if a parent to Minions, spells and encahntments
class Card {
protected:
	std::string name;
  public:
	  //Card();
	  Card(std::string name);
	  virtual ~Card() = 0;
	  virtual void attack(Card *minion);
	  virtual void attack(Player *player);
	  virtual void changeAttack(int attack);
	  virtual void changeDefence(int defence);
	  std::string getName();
	  virtual void addToBoard(Card *ritualSlot, Card *MinionCardForEnch, Slot *slot);
};


#endif

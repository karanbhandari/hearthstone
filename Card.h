#ifndef _CARD_H_
#define _CARD_H_

#include <string>
#include <sstream>
#include <iostream>
#include "Deck.h"

class Player;
class Minion;

// this is an abstract cards class that if a parent to Minions, spells and encahntments
class Card {
protected:
	std::string name;
	int cardCost;
  public:
	  //Card();
	Card(std::string name);
	virtual ~Card() = 0;
	virtual void attack(Card *minion);
	virtual void attack(Player *player);
	virtual void changeAttack(int attack);
	virtual void changeDefence(int defence);
	virtual void performActivatedAbility(int minionNum, Minion *minion, Player *p1, Player *p2);
	virtual void performTriggeredAbility(std::string what, int minionNum, Minion *minion, Player *p1, Player *p2);
	std::string getName();
	virtual void addToBoard(Card *ritualSlot, Card *MinionCardForEnch, Slot *slot);
	virtual void popTopEnchantment();
   	//virtual void reInitializeDefence(int initialisationVali) = 0;
	virtual int power();
	virtual void updateCharge(int val);
	virtual void setActionTo1();
	int getCardCost();
};


#endif

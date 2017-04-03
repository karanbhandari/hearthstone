#ifndef __ENCHANTMENTS_H__
#define __ENCHANTMENTS_H__

#include <string>
#include <sstream>
#include <iostream>
//#include "Card.h"
#include "Minion.h"
#include "Ability.h"

class Enchantment: public Card {
<<<<<<< HEAD
	int cost;
	// int changeAttack;
	// int changeDefence;
    Ability *triggeredAbility;
    Ability *activatedAbility;
    // std::string function;
  public:
    Enchantment(const std::string name, int cost/*, int changeAttack, int changeDefence, const std::string function*/, Ability *activatedAbility, Ability *triggeredAbility);
    ~Enchantment();
    void setAbility(Minion *minion);
    void performActivatedAbility(int minionNum, Minion *minion, Player *p1, Player *p2) override;
    int getCost();
};

#endif

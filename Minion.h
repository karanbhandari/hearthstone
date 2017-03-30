#ifndef __MINIONS_H__
#define __MINIONS_H__

#include <string>
#include <sstream>
#include <iostream>
#include "Player.h"
#include "Ability.h"
#include "Cards.h"

class Minions: public Cards {
	std::string name;
    int attack;
    int defence;
    int action; // What is this going to do and how its type is int is still a confusion for me
    Ability *activatedAbility;
    Ability *triggeredAbility;
    Enchantment **Enchantments;
  public:
    Minions (const std::string& name,int attack, int defence, int action, Ability *actAbl, Ability *trgAbl, Ability *newstActAbl);
    void updateActivatedAbility ();
    void resetDefault();
    void setDescription(const std::string desc);
    void attackMinion(Minions *minion);
    // there probably needs to be a funstion to reduce the defence of minion on attack
    // name them minionAttacks and reduceDefence @Karan
    void performAbility();
};

#endif

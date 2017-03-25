#ifndef __MINIONS_H__
#define __MINIONS_H__

#include <string>
#include <sstream>
#include <iostream>
#include "Player.h"
#include "Ability.h"
#include "Card.h"

class Minions: public Cards {
    int attack;
    int defence;
    int action; // What is this going to do and how its type is int is still a confusion for me
    Ability *activatedAbility;
    Ability *triggeredAbility;
    Ability *newestActivatedAbility;
  public:
    Minions (int attack, int defence, int action, Ability *actAbl, Ability *trgAbl, Ability *newstActAbl);
    void updateActivatedAbility ();
    void resetDefault();
    void attackMinion(Minions *minion);
    // there probably needs to be a funstion to reduce the defence of minion on attack
    // name them minionAttacks and reduceDefence @Karan
    void performAbility();
};

#endif
#ifndef __RITUALS_H__
#define __RITUALS_H__

#include <string>
#include <sstream>
#include <iostream>
#include "Card.h"
#include "Minion.h"
#include "Ability.h"

class Ritual: public Card {
	int charge;
	int cost;
	int activationCost;
    Ability *triggeredAbility;
  public:
    Ritual(const std::string &name, int cost, int charge, int activationCost, Ability *ability);
    ~Ritual();
    void performAbility(Minion *minion);
    void updateCharge(int val) override;
    void performTriggeredAbility(std::string what, int minionNum, Minion *minion, Player *p1, Player *p2);
    int power();
};

#endif

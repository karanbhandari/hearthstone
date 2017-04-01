#ifndef __RITUALS_H__
#define __RITUALS_H__

#include <string>
#include <sstream>
#include <iostream>
#include "Card.h"
#include "Minion.h"
#include "Ability.h"

class Ritual: public Card {
	std::string name;
	int charge;
	int activationCost;
    Ability *triggeredAbility;
  public:
    Ritual(const std::string &name, int charge, int activationCost, Ability *ability);
    ~Ritual();
    void performAbility(Minion *minion);
    void addToBoard(Card *ritualSlot, Card *MinionCardForEnch, Slot *slot) override;
};

#endif

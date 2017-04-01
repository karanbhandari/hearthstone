#ifndef __ENCHANTMENTS_H__
#define __ENCHANTMENTS_H__

#include <string>
#include <sstream>
#include <iostream>
//#include "Card.h"
#include "Minion.h"
#include "Ability.h"

class Enchantment: public Card {
	int cost;
	int changeAttack;
	int changeDefence;
    Ability *triggeredAbility;
    std::string function;
  public:
    Enchantment(const std::string &name, int cost, int changeAttack, int changeDefence, const std::string &function, Ability *ability);
    ~Enchantment();
    void setAbility(Minion *minion);
    void addToBoard(Card *ritualSlot, Card *MinionCardForEnch, Slot *slot) override;
};

#endif

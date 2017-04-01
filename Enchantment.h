#ifndef __ENCHANTMENTS_H__
#define __ENCHANTMENTS_H__

#include <string>
#include <sstream>
#include <iostream>
//#include "Card.h"
#include "Minion.h"
#include "Ability.h"

class Enchantment: public Card {
	std::string name;
	int cost;
	int changeAttack;
	int changeDefence;
    Ability *triggeredAbility;
  public:
    Enchantment(const string &name, int cost, int changeAttack, int changeDefence, Ability *ability);
    ~Enchantment();
    void setAbility(Minion *minion);
    void addToBoard(Card *ritualSlot, Card *MinionCardForEnch, Slot *slot) override;
};

#endif

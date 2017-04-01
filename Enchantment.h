#ifndef __ENCHANTMENTS_H__
#define __ENCHANTMENTS_H__

#include <string>
#include <sstream>
#include <iostream>
//#include "Card.h"
#include "Minion.h"
#include "Ability.h"

class Enchantment: public Card {
    Ability *ability;
  public:
    Enchantment(Ability *ability);
    ~Enchantment();
    void setAbility(Minions *minion);
    void addToBoard(Card *ritualSlot, Card *MinionCardForEnch, Slot *slot) override;
};

#endif

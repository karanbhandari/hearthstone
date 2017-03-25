#ifndef __ENCHANTMENTS_H__
#define __ENCHANTMENTS_H__

#include <string>
#include <sstream>
#include <iostream>
//#include "Card.h"
#include "Minion.h"
#include "Ability.h"

class Enchantments: public Cards {
    Ability *ability;
  public:
    Enchantments(Ability *ability);
    void setAbility(Minions *minion);
};

#endif
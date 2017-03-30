#ifndef __RITUALS_H__
#define __RITUALS_H__

#include <string>
#include <sstream>
#include <iostream>
#include "Cards.h"
#include "Minion.h"
#include "Ability.h"

class Rituals: public Cards {
    Ability *triggeredAbility;
  public:
    Rituals(Ability *ability);
    void performAbility(Minions *minion);
};

#endif

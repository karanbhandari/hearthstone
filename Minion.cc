#include <string>
#include <sstream>
#include "Minion.h"
#include "Player.h"
#include "Ability.h"

using namespace std;

Minions::Minions (const string &name,int attack, int defence, int action, Ability *actAbl, Ability *trgAbl, Ability *newstActAbl): name{name},
  attack{attack}, defence{defence}, action{action}, activatedAbility{actAbl}, triggeredAbility{trgAbl},
  newestActivatedAbility{newstActAbl} {
}

void updateActivatedAbility (){
  // updates the activated ability
}

void resetDefault(){
  // Not sure what is being defaulted here.. probably removing the spell or sth @Karan
}

void attackMinion(Minions *minion){
  // Not sure if this is informing other minion about hte attack or reduces current minions defence @Karan
}

void performAbility(){
  // performs ability
}

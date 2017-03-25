#include <string>
#include <sstream>
#include "Enchantment.h"
#include "Player.h"
#include "Ability.h"

using namespace std;

Enchantments::Enchantments(Ability *ability): ability{ability} {
}

void setAbility(Minions *minion){
  // Not sure if this is informing other minion about hte attack or reduces current Enchantments defence @Karan
}

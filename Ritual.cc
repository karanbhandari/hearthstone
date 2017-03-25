#include <string>
#include <sstream>
#include "Ritual.h"
#include "Player.h"
#include "Ability.h"

using namespace std;

Rituals::Rituals(Ability *ability): triggeredAbility{ability} {
}

void performAbility(Minions *minion){
  // Not sure if this is informing other minion about hte attack or reduces current Rituals defence @Karan
}

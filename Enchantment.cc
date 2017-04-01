#include <string>
#include <sstream>
#include "Enchantment.h"
#include "Player.h"
#include "Ability.h"

using namespace std;

Enchantment::Enchantment(Ability *ability): ability{ability} {
}

Enchantment::~Enchantment() {
	delete ability;
}

void Enchantment::setAbility(Minions *minion){
  // Not sure if this is informing other minion about hte attack or reduces current Enchantments defence @Karan
}

void Enchantment::addToBoard(Card *ritualSlot, Card *MinionCardForEnch, Slot *slot){
	// passes the card on to the Minion which would add the card to its list of echantments
	MinionCardForEnch->updateActivatedAbility(this);	
}

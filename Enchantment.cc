#include <string>
#include <sstream>
#include "Enchantment.h"
#include "Player.h"
#include "Ability.h"

using namespace std;

Enchantment::Enchantment(const string &name, int cost, int changeAttack, int changeDefence, Ability *ability): 
		name(name), cost(cost), changeAttack(changeAttack), changeDefence(changeDefence), triggeredAbility{ability} {
}

Enchantment::~Enchantment() {
	delete ability;
}

void Enchantment::setAbility(Minion *minion){
  // Not sure if this is informing other minion about hte attack or reduces current Enchantments defence @Karan
}

void Enchantment::addToBoard(Card *ritualSlot, Card *MinionCardForEnch, Slot *slot){
	// passes the card on to the Minion which would add the card to its list of echantments
	//Minion *temp  = MinionCardForEnch;
 	//temp->updateActivatedAbility(this);	
}

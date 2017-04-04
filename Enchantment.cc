#include <string>
#include <sstream>
#include "Enchantment.h"
#include "Player.h"
#include "Ability.h"

using namespace std;

Enchantment::Enchantment(const string name, int cost, /*int changeAttack, int changeDefence,*/  Ability *activatedAbility, Ability *triggeredAbility):
		Card{name, cost}, cost(cost),/* changeAttack(changeAttack), changeDefence(changeDefence), function{function},*/activatedAbility{activatedAbility}, triggeredAbility{triggeredAbility} {
}

Enchantment::~Enchantment() {
	delete triggeredAbility;
	triggeredAbility = nullptr;
	delete activatedAbility;
	activatedAbility = nullptr;
}

void Enchantment::setAbility(Minion *minion){
  // Not sure if this is informing other minion about hte attack or reduces current Enchantments defence @Karan
}

Ability* Enchantment::getAbility() {
	if(activatedAbility)
		return activatedAbility;
	return triggeredAbility;
}


void Enchantment::performActivatedAbility(int minionNum, Minion *minion, Player *p1, Player *p2) {
	cout << "Enchantment ability being performed here" << endl;
}

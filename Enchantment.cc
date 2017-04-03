#include <string>
#include <sstream>
#include "Enchantment.h"
#include "Player.h"
#include "Ability.h"

using namespace std;

Enchantment::Enchantment(const string name, int cost, int changeAttack, int changeDefence, const string function, Ability *ability):
		Card{name, cost}, changeAttack(changeAttack), changeDefence(changeDefence), function{function}, triggeredAbility{ability} {
}

Enchantment::~Enchantment() {
	delete triggeredAbility;
}

void Enchantment::setAbility(Minion *minion){
  // Not sure if this is informing other minion about hte attack or reduces current Enchantments defence @Karan
}


void Enchantment::performActivatedAbility(int minionNum, Minion *minion, Player *p1, Player *p2) {
	cout << "Enchantment ability being performed here" << endl;
}

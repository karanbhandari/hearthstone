#include <string>
#include <sstream>
#include "Minion.h"
#include "Player.h"
#include "Ability.h"

using namespace std;

Minion::Minion(const string &name,int attack, int defence, int action, Ability *actAbl, Ability *trgAbl): Card{name},
  attack{attack}, defence{defence}, action{action}, activatedAbility{actAbl}, triggeredAbility{trgAbl} {
}

Minion::~Minion() {
  delete activatedAbility;
  delete triggeredAbility;
  // ?? Do we also need to delete the vector??
}

void Minion::updateActivatedAbility(Card *Ench){
  // updates the activated ability by adding Enchantment to the vector of enchantments
  enchantments.push_back(Ench);
}

void Minion::resetDefault(){
  // Removes the enchantments if any on the Minion
	while(!enchantments.empty()){
    enchantments.pop_back();
  }
}

void Minion::attackOther(Minion *minion){
	// reduces the this->defence by the minion->attack, and minion->defence by this->attack
	if(this->action){
    minion->defence -= this->attack;
    this->defence -= minion->attack;
  }
  this->action = 0;
}

void Minion::attackOther(Player *player){
  // reduces the this->defence by the minion->attack, and minion->defence by this->attack
  if(this->action){
    // reduce the player's life by one
    player->changeLife(-1);
  }
  this->action = 0;
}

void Minion::performAbility(){
  // performs ability
}

void Minion::performActivatedAbility(int minionNum, Minion *minion, Player *p1, Player *p2) {
  if (enchantments.empty()) {
    if (p1->getMagic() >= activatedAbility->getCost()) {
        p1->changeMagic(-1);
        activatedAbility->performActivatedAbility(" ", minionNum, minion, p1, p2);
    } else {
      cout << "You don't have enough magic to play this" << endl;
    }
  } else {
    Enchantment *top = enchantments.back();
    top->performActivatedAbility(minionNum, minion, p1, p2);
  }
}


void Minion::performTriggeredAbility(std::string what, int minionNum, Minion *minion, Player *p1, Player *p2) {
  triggeredAbility->performTriggeredAbility(what, minionNum, this, minion, p1, p2);
}

bool Minion::isDead() {
	// returns true if the minion is dead
	return (this->defence <= 0);
}

void Minion::addToBoard(Card *ritualSlot, Card *MinionCardForEnch, Slot *slot){
  // calls absractDeck's add card functionality
  //slot->add(this);
}

void Minion::changeAttack(int val) {
  this->attack += val;
};

void Minion::changeDefence(int val) {
  this->defence += val;
};

void Minion::popTopEnchantment() {
  if(enchantments.size() > 0) {
    enchantments.pop_back();
  }
}

void Minion::reIntializeDefence(int initialisationVal) {
  defence = initialisationVal;
}

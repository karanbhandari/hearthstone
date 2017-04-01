#include <string>
#include <sstream>
#include "Minion.h"
#include "Player.h"
#include "Ability.h"

using namespace std;

Minion::Minion(const string &name,int attack, int defence, int action, Ability *actAbl, Ability *trgAbl, Ability *newstActAbl): name{name},
  attack{attack}, defence{defence}, action{action}, activatedAbility{actAbl}, triggeredAbility{trgAbl},
  newestActivatedAbility{newstActAbl} {
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
	while(enchantments){
    enchantments.pop_back();
  }
}

void Minion::attack(Minion *minion){
	// reduces the this->defence by the minion->attack, and minion->defence by this->attack
	if(this->action){
    minion->defence -= this->attack;
    this->defence -= minion->attack;
  }
  this->action = 0;
}

void Minion::attack(Player *player){
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

bool Minion::isDead() {
	// returns true if the minion is dead
	return (this->defence <= 0);
}

void Minion::addToBoard(Card *ritualSlot, Card *MinionCardForEnch, Slot *slot){
  // calls absractDeck's add card functionality
  slot->add(this);
}

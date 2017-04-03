#include <iostream>
#include <string>
#include <sstream>
#include "Minion.h"
#include "Player.h"
#include "Ability.h"
#include "Enchantment.h"

#define dbg true

using namespace std;

Minion::Minion(const string &name,int attack, int defence, int cost, Ability *actAbl, Ability *trgAbl): Card{name, cost},
  attack{attack}, defence{defence}, activatedAbility{actAbl}, triggeredAbility{trgAbl} {
    action = 1;
}

Minion::~Minion() {
  delete activatedAbility;
  activatedAbility = nullptr;
  delete triggeredAbility;
  triggeredAbility = nullptr;
  for(auto &c : enchantments) 
    delete c;
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
 	 }
  this->action = 0;
}

void Minion::attackOther(Player *player){
  // reduces the this->defence by the minion->attack, and minion->defence by this->attack
  if(this->action > 0){
    // reduce the player's life by one
    player->changeLife(-1);
  } else {
    cout << "You don't have enought action to attack" << endl;
  }
  this->action = 0;
}

void Minion::performAbility(){
  // performs ability
}

void Minion::performActivatedAbility(int minionNum, Minion *minion, Player *p1, Player *p2) {
  if (enchantments.empty()) {
        ActivatedAbility *ab = dynamic_cast<ActivatedAbility*>(activatedAbility);
	if(dbg) cout << "Performing Activated Ability with act Cost " << ab->getActCost() << " and player Magic " << p1->getMagic() << endl;
	if(p1->getMagic() >= ab->getActCost()) {
          ab->performAbility(" ", minionNum, minion, p1, p2);
          p1->changeMagic(ab->getActCost() * -1);
        } else {
          cout << "You don't have enough magic to use this ability" << endl;
        }
  } else {
    Enchantment *top = dynamic_cast<Enchantment*>(enchantments.back());
    top->performActivatedAbility(minionNum, minion, p1, p2);
  }
}


void Minion::performTriggeredAbility(string what, int minionNum, Minion *minion, Player *p1, Player *p2) {
  //auto tAbility = dynamic_cast<TriggeredAbility*>(triggeredAbility);
  if(dbg) cout << "Enter Minion For perfromTriggeredAbility" << endl;
  if(triggeredAbility) {
    if (dbg) cout << "triggeredAbility is not nullptr" << endl; 
    dynamic_cast<TriggeredAbility*>(triggeredAbility)->performTAbility(what, minionNum, this, minion, p1, p2);
  }
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

void Minion::reInitializeDefence(int initialisationVal) {
  defence = initialisationVal;
}

void Minion::setActionTo1() {
  action = 1;
}

bool Minion::hasAbility() {
	return !(triggeredAbility == nullptr && activatedAbility == nullptr);
}
bool Minion::hasTriggeredAbility(){
	return !(triggeredAbility == nullptr);
}
int Minion::getAttack() {
	return attack;
}
int Minion::getCost(){
	return getCardCost();
}
int Minion::getDefence() {
	return defence;
}
int Minion::getAction() {
	return action;
}
Ability* Minion::getAbility() {
	if (activatedAbility == nullptr) {
		return triggeredAbility;
	}
	return activatedAbility;
}

int Minion::getActAbilityCost() {
	if(activatedAbility)
		return dynamic_cast<ActivatedAbility*>(activatedAbility)->getActCost();
	return -1;
}

void Minion::setActAbilityCost(int setVal) {
  activatedAbility->changeActCost(setVal);
}

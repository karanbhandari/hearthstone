#include <string>
#include <sstream>
#include "Ritual.h"
#include "Player.h"
#include "Ability.h"

using namespace std;

Ritual::Ritual(const string &name, int cost, int charge, int activationCost, Ability *ability):
		Card{name, cost}, charge(charge), activationCost(activationCost), triggeredAbility{ability} {
}

Ritual::~Ritual() {
	delete triggeredAbility;
	triggeredAbility = nullptr;
}

void Ritual::performAbility(Minion *minion){
  // Not sure if this is informing other minion about hte attack or reduces current Rituals defence @Karan
}


void Ritual::updateCharge(int val) {
	charge += val;
}

void Ritual::performTriggeredAbility(std::string what, int minionNum, Minion *minion, Player *p1, Player *p2) {
	if(charge - activationCost < 0) 
		return;
	triggeredAbility->performTAbility(what, minionNum, nullptr, minion, p1, p2);
	cout << "ritual " << what << " Ability Plays"<< endl;
	if(what == "minionEnter")
		charge -= activationCost; 
}

int Ritual::power() {
	return charge;
}

int Ritual::getCharge(){
	return charge;
}
int Ritual::getCost(){
	return getCardCost();
}
int Ritual::getActivateCost(){
	return activationCost;
}

Ability * Ritual::getAbility(){
	return triggeredAbility;
}

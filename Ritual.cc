#include <string>
#include <sstream>
#include "Ritual.h"
#include "Player.h"
#include "Ability.h"

using namespace std;

Ritual::Ritual(const string &name, int charge, int activationCost, Ability *ability): 
		Card{name}, charge(charge), activationCost(activationCost), triggeredAbility{ability} {
}

Ritual::~Ritual() {
	delete triggeredAbility;
}

void Ritual::performAbility(Minion *minion){
  // Not sure if this is informing other minion about hte attack or reduces current Rituals defence @Karan
}

void Ritual::addToBoard(Card *ritualSlot, Card *MinionCardForEnch, Slot *slot){
	// adds the ritual to its slot on the player's board and delete the previous one if any
	delete ritualSlot;
	ritualSlot = this;
}

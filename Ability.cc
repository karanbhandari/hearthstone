#include "Ability.h"
#include <string>
#include <iostream>
#include "Ability.h"

using namespace std;

Ability::Ability(const string name) {
	this->name = name;
}
// void Ability::performAbility() {
// 	cout << "Ability Activated! \n";
// }

TriggeredAbility::TriggeredAbility(const string &nameOfAbility): Ability{nameOfAbility} {
}

void TriggeredAbility::performAbility() {
	// performs the ability call
}	

void TriggeredAbility::startOfTurn() {
	// triggeres all the startof turn abilities
	// 1: Restores the action to minion to 1, and it
	
}

void TriggeredAbility::endOfTurn() {

}

void TriggeredAbility::minionEnter() {
	if(name == "Whenever an opponent’s minion enters play, deal 1 damage to it."){
		// reduce opponent'minion's defence by one on enter. (this is fire elemental)
	}
}

void TriggeredAbility::minionLeave() {
	if(name == "Gain +1/+1 whenever a minion leaves play."){
		// reduce this increase attack and defence by 1(this is Bone Golem)
	} else {
		// 
	}
}

ActivatedAbility::ActivatedAbility(const string& nameOfAbility) : Ability{nameOfAbility}{

}

void ActivatedAbility::performAbility() {
	
}

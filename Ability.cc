#include "Ability.h"
#include <string>
#include <iostream>
#include "Ability.h"

using namespace std;

Ability::Ability(const string & name) {
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

}

void TriggeredAbility::minionLeave() {

}

ActivatedAbility::ActivatedAbility(const string& nameOfAbility) {

}

void ActivatedAbility::performAbility() {

}

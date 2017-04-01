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

void TriggeredAbility::performAbility(string what, Minion *minion, Player *player) {
	if (what == "minionLeave") {
		minionLeave(minion, player);
	} else if (what == "minionEnter") {
		minionEnter(minion, player);
	} else if (what == "endOfTurn") {
		endOfTurn(minion, player);
	} else if (what == "startOfTurn") {
		startOfTurn(minion, player);
	}
 	// performs the ability call
}	

void TriggeredAbility::startOfTurn() {
	// triggeres all the startof turn abilities
	// 1: Restores the action to minion to 1, and it
	
}

void TriggeredAbility::endOfTurn(Minion *minion, Player *player) {
	if (name == "At the end of your turn, all your minions gain +0/+1.") {
		player->updateSlot(0, 1); //TODO: add this function 
	} 
}

void TriggeredAbility::minionEnter(Minion *minion, Player *player) {
	if (name == "Whenever an opponent’s minion enters play, deal 1 damage to it."){
		// reduce opponent'minion's defence by one on enter. (this is fire elemental)
		minion->changeDefence(-1);
	}
}

void TriggeredAbility::minionLeave(Minion *minion, Player *player) {
	if(name == "Gain +1/+1 whenever a minion leaves play."){
		minion->changeAttack(1);
		minion->changeDefence(1);
		// reduce this increase attack and defence by 1(this is Bone Golem)
	} else {
		// 
	}
}

ActivatedAbility::ActivatedAbility(const string& nameOfAbility) : Ability{nameOfAbility}{

}

void ActivatedAbility::performAbility(Minion *minion, Player *player) {
	if (name == "Deal 1 damage to target minion") {
		minion->changeDefence(-1);
	} else if (name == "Summon a 1/1 air elemental") {
		const string minionName = "Air Elemental";
		Ability * actAb = nullptr;
		Ability * trigAb = nullptr;
		Minion * myMinion = new Minion(minionName, 1, 1, 0, actAb, trigAb);
		player->addCard("Slot", myMinion);
	} else if (name == "Summon up to three 1/1 air elementals") {
		const string minionName = "Air Elemental";
		Ability * actAb = nullptr;
		Ability * trigAb = nullptr;
		Minion * myMinion = new Minion(minionName, 1, 1, 0, actAb, trigAb);
		Minion * myMinion2 = new Minion(minionName, 1, 1, 0, actAb, trigAb);
		Minion * myMinion3 = new Minion(minionName, 1, 1, 0, actAb, trigAb);
		player->addCard("Slot", myMinion);
		player->addCard("Slot", myMinion2);
		player->addCard("Slot", myMinion3);
	}
}

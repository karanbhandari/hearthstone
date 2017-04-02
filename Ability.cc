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

Ability::~Ability() {}

void Ability::performAbility() {}


TriggeredAbility::TriggeredAbility(const string &nameOfAbility): Ability{nameOfAbility} {
}

void TriggeredAbility::performAbility(string what, int minionNum, Minion *minion, Player *actPlayer, Player *inactPlayer) {
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

void TriggeredAbility::performAbility(string what, int minionNum, Ritual *ritual, Player *actPlayer, Player *inactPlayer) {
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
		// TODO: remove all the enchantments
	}
}

ActivatedAbility::ActivatedAbility(const string& nameOfAbility) : Ability{nameOfAbility}{

}

void ActivatedAbility::performAbility(string what, int minionNum, Minion *minion, Player *actPlayer, Player *inactPlayer) {
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
	} else if (name == "Destroy target minion or ritual") {
	// destroys the minion since banish has been called
    player->removeCard(minionNum);
  } else if (name == "Return target minion to its owners hand") {
    // returns the minion to the hand of the player since Unsummon is called
    player->returnMinionToHand(minionNum, minion);
  } else if (name == "Destroy the top enchantment on target minion") {
    // need to destroy the minion's top enchantment
    player->destroyTopEnchantment(minionNum);
  } else if(name =="Resurrect the top minion in your graveyard and set its defence to 1") {
    // Return the top graveyard card to the slot
    player->raiseTheDead();
  } else if (name ==  "Deal 2 damage to all minions") {
    // damage all the minions on slot with 2 atttack
    player->updateSlot(0,-2);
  }
}


void ActivatedAbility::performAbility(string what, int minionNum, Ritual *ritual, Player *actPlayer, Player *inactPlayer) {
  if(name == "Destroy target minion or ritual"){
    // Destroys the ritual since Banish has been called
    player->removeCard("Ritual", minion);
  } else if (name ==  "Your ritual gains 3 charges") {
    // ritual gains three charges since recharge is calleed
    player->updateRitual(3);
  }
}

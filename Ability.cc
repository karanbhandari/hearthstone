#include "Ability.h"
#include <string>
#include <iostream>
#include "Ability.h"
#include "Player.h"

#define dbg false

using namespace std;

Ability::Ability(const string name) {
	this->name = name;
}
// void Ability::performAbility() {
// 	cout << "Ability Activated! \n";
// }
string Ability::getName(){
	return name;
}

Ability::~Ability() {}

void Ability::performAbility(std::string what, int minionNum, Minion *minion, Player *actPlayer, Player *inactPlayer) {}; 
void Ability::performAbility(std::string what, int minionNum, Ritual *ritual, Player *actPlayer, Player *inactPlayer) {};
void Ability::performTAbility(std::string what, int minionNum, Minion *thisMinion, Minion *minion, Player *actPlayer, Player *inactPlayer) {};

///////////////////////////////////////*****Triggered ability*****///////////////////////////////////////

TriggeredAbility::TriggeredAbility(const string &nameOfAbility): Ability{nameOfAbility} {
}

void TriggeredAbility::performAbility(string what, int minionNum, Minion *minion, Player *actPlayer, Player *inactPlayer) {
	// if (what == "minionLeave") {
	// 	minionLeave(minion, player);
	// } else if (what == "minionEnter") {
	// 	minionEnter(minion, player);
	// } else if (what == "endOfTurn") {
	// 	endOfTurn(minion, player);
	// } else if (what == "startOfTurn") {
	// 	startOfTurn(minion, player);
	// }
 	// performs the ability call
}

void TriggeredAbility::performAbility(string what, int minionNum, Ritual *ritual, Player *actPlayer, Player *inactPlayer) {
}

void TriggeredAbility::performTAbility(string what, int minionNum, Minion *thisMinion, Minion *opponentMinion, Player *actPlayer, Player *inactPlayer) {
  if(dbg) cout << "what is : " ;
  if(dbg) cout << what << endl;
  if (what == "minionLeave") {
    minionLeave(thisMinion, opponentMinion, actPlayer, inactPlayer);
  } else if (what == "minionEnter") {
    minionEnter(thisMinion, opponentMinion, actPlayer, inactPlayer);
  } else if (what == "endOfTurn") {
    endOfTurn(thisMinion, opponentMinion, actPlayer, inactPlayer);
  } else if (what == "startOfTurn") {
    startOfTurn(thisMinion, opponentMinion, actPlayer, inactPlayer);
  }
};


void TriggeredAbility::startOfTurn(Minion *thisMinion, Minion *opponentMinion, Player *actPlayer, Player *inactPlayer) {
	// triggeres all the startof turn abilities
	// 1: Restores the action of minion to 1, and it
	// 2: adds one magic to the player
  // 3: check of there is a ritual then play it
  if(name == "At the start of your turn, gain 1 magic") {
    if(actPlayer->powerOfRitual() > 0){
      actPlayer->changeMagic(1);
      // actPlayer->updateRitual(-1);
    }
  }
}

void TriggeredAbility::endOfTurn(Minion *thisMinion, Minion *opponentMinion, Player *actPlayer, Player *inactPlayer) {
	if (name == "At the end of your turn, all your minions gain +0/+1.") {
		actPlayer->updateSlot(0, 1); //TODO: add this function (this is potion seller)
	} 
}

void TriggeredAbility::minionEnter(Minion *thisMinion, Minion *opponentMinion, Player *actPlayer, Player *inactPlayer) {
  //if(dbg) cout << "the name of the ability " << thisMinion->getName() << " has is " << name << endl;
  if (name == "Whenever an opponents minion enters play, deal 1 damage to it."){
		// reduce opponent'minion's defence by one on enter. (this is fire elemental)
		if(dbg) cout << "reached at minion Enter for file Elementer and opponent minion name is: " << opponentMinion->getName() << endl;
		if (thisMinion != opponentMinion && actPlayer->getSlot()->cardBelongsTo(thisMinion) == -1)
			opponentMinion->changeDefence(-1);
  } else if(name == "Whenever a minion enters play under your control, it gains +1/+1") {
    opponentMinion->changeDefence(1);
    opponentMinion->changeAttack(1); // it ays opponent but it actually is passed the actual minnion
  } else if(name == "Whenever a minion enters play, destroy it") {
    opponentMinion->reInitializeDefence(-1);
    //TODO: @Hitanshu has to check for sending the minion to the graveyard
  }
}

void TriggeredAbility::minionLeave(Minion *thisMinion, Minion *opponentMinion, Player *actPlayer, Player *inactPlayer) {
	if(name == "Gain +1/+1 whenever a minion leaves play."){
		thisMinion->changeAttack(1); // TODO: change to the activated playe'rs change
		thisMinion->changeDefence(1);
		// reduce this increase attack and defence by 1(this is Bone Golem)
	} else {
		// TODO: remove all the enchantments
	}
}

///////////////////////////////////////*****Activated ability*****///////////////////////////////////////


ActivatedAbility::ActivatedAbility(const string& nameOfAbility, int cost) 
	: Ability{nameOfAbility}, actCost{cost} {

}

int ActivatedAbility::getActCost() {
	return actCost;
}

void ActivatedAbility::performAbility(string what, int minionNum, Minion *minion, Player *actPlayer, Player *inactPlayer) {
	if (name == "Deal 1 damage to target minion") {
		minion->changeDefence(-1);
	} else if (name == "Summon a 1/1 air elemental") {
		const string minionName = "Air Elemental";
		Ability * actAb = nullptr;
		Ability * trigAb = nullptr;
		Minion * myMinion = new Minion(minionName, 1, 1, 0, actAb, trigAb);
		actPlayer->addCard("Slot", myMinion);
	} else if (name == "Summon up to three 1/1 air elementals") {
		const string minionName = "Air Elemental";
		Ability * actAb = nullptr;
		Ability * trigAb = nullptr;
		Minion * myMinion = new Minion(minionName, 1, 1, 0, actAb, trigAb);
		Minion * myMinion2 = new Minion(minionName, 1, 1, 0, actAb, trigAb);
		Minion * myMinion3 = new Minion(minionName, 1, 1, 0, actAb, trigAb);
		actPlayer->addCard("Slot", myMinion);
		actPlayer->addCard("Slot", myMinion2);
		actPlayer->addCard("Slot", myMinion3);
	} else if (name == "Destroy target minion or ritual") {
	// destroys the minion since banish has been called
    inactPlayer->removeCard(minionNum);
  } else if (name == "Return target minion to its owners hand") {
    // returns the minion to the hand of the player since Unsummon is called
    inactPlayer->returnMinionToHand(minionNum, minion);
  } else if (name == "Destroy the top enchantment on target minion") {
    // need to destroy the minion's top enchantment
    inactPlayer->destroyTopEnchantment(minionNum);
  } else if(name =="Resurrect the top minion in your graveyard and set its defence to 1") {
    // Return the top graveyard card to the slot
    actPlayer->raiseTheDead();
  } else if (name ==  "Deal 2 damage to all minions") {
    // damage all the minions on slot with 2 atttack
    inactPlayer->updateSlot(0,-2);
  } else if(name == "Enchanted minion gains +2/+2") {
  	// minion gains +2/+2
  	minion->changeAttack(2);
  	minion->changeDefence(2);
  } else if(name == "Enchanted minion gains *2/*2") {
  	// minion gains *2/*2
  	int myAttack = minion->getAttack();
  	int myDefence = minion->getDefence();
  	myAttack = myAttack*2 - myAttack;
  	myDefence = myDefence*2 - myDefence;
  	minion->changeAttack(myAttack);
  	minion->changeDefence(myDefence);
  } else if(name == "Enchanted minion’s activated ability costs 2 more") {
  	// activated ability would cost two more
  	int currentActCost = minion->getActAbilityCost();
  	minion->setActAbilityCost(2);
  }
}


void ActivatedAbility::performAbility(string what, int minionNum, Ritual *ritual, Player *actPlayer, Player *inactPlayer) {
  if(name == "Destroy target minion or ritual"){
    // Destroys the ritual since Banish has been called
	inactPlayer->deleteRitual(); 
 } else if (name ==  "Your ritual gains 3 charges") {
    // ritual gains three charges since recharge is calleed
    actPlayer->updateRitual(3);
  }
}

void ActivatedAbility::changeActCost(int val) {
	actCost = val;
}

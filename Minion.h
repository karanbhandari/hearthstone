#ifndef __MINIONS_H__
#define __MINIONS_H__

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Ability.h"
#include "Cards.h"

class Minion: public Card {
	std::string name;
    int attack;
    int defence;
    int action; // What is this going to do and how its type is int is still a confusion for me
    Ability *activatedAbility;
    Ability *triggeredAbility;
    std::vector<Enchantment*> enchantments;
  public:
    Minion(const std::string& name,int attack, int defence, int action, Ability *actAbl, Ability *trgAbl, Ability *newstActAbl);
    ~Minion();
    void updateActivatedAbility ();
    void resetDefault();
    void setDescription(const std::string desc);
    void attack(Minion *minion);
    void attack(Player *player);
    // there probably needs to be a funstion to reduce the defence of minion on attack
    // name them minionAttacks and reduceDefence @Karan
    void performAbility();
    bool isDead();
    void addToBoard(Card *ritualSlot, Card *MinionCardForEnch, Slot *slot) override;
};

#endif

#ifndef __MINIONS_H__
#define __MINIONS_H__

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "Card.h"

class Player;
class Ability;
class Minion;
class Enchantment;

class Minion: public Card {
	int attack;
	int defence;
	int action; // What is this going to do and how its type is int is still a confusion for me
	Ability *activatedAbility;
	Ability *triggeredAbility;
	std::vector<Card*> enchantments;
public:
	Minion(const std::string& name, int attack, int defence, int action,
			Ability *actAbl, Ability *trgAbl);
	~Minion();
	void updateActivatedAbility(Card *Enchantment);
	void resetDefault();
	void setDescription(const std::string desc);
	void attackOther(Minion *minion);
	void attackOther(Player *player);
	// there probably needs to be a funstion to reduce the defence of minion on attack
	// name them minionAttacks and reduceDefence @Karan
	void performAbility();
	bool isDead();
	void addToBoard(Card *ritualSlot, Card *MinionCardForEnch, Slot *slot)
			override;
	void changeAttack(int changeByValue) override;
	void changeDefence(int changeByValue) override;
	void popTopEnchantment() override;
	void reInitializeDefence(int initialisationVal);
	void performActivatedAbility(int minionNum, Minion *minion, Player *p1,
			Player *p2) override;
	void performTriggeredAbility(std::string what, int minionNum,
			Minion *minion, Player *p1, Player *p2) override;
	void setActionTo1() override;
	int getCost();
	int getAttack();
	int getDefence();
	int getAction();
	Ability* getAbility();
	int getActAbilityCost();
	bool hasAbility();
	bool hasTriggeredAbility();
};

#endif

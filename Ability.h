#ifndef __ABILITY_H__
#define __ABILITY_H__

#include <string>
#include <sstream>
#include <iostream>

class Minion;
class Player;
class Ritual;

class Ability {
  protected:
	 std::string name;

  public:
    Ability(const std::string nameOfAbility);
    virtual void performAbility(std::string what, int minionNum, Minion *minion, Player *actPlayer, Player *inactPlayer); 
    virtual void performAbility(std::string what, int minionNum, Ritual *ritual, Player *actPlayer, Player *inactPlayer);
    virtual void performTAbility(std::string what, int minionNum, Minion *thisMinion, Minion *minion, Player *actPlayer, Player *inactPlayer);
    virtual ~Ability();
};

class TriggeredAbility: public Ability {
	// name is inherited from the parent class
	public: 	
    TriggeredAbility(const std::string& nameOfAbility);
    void performAbility(std::string what, int minionNum, Minion *minion, Player *actPlayer, Player *inactPlayer)  override;
    void performAbility(std::string what, int minionNum, Ritual *ritual, Player *actPlayer, Player *inactPlayer) override;
    void performTAbility(std::string what, int minionNum, Minion *thisMin, Minion *minion, Player *actPlayer, Player *inactPlayer) override;
    void startOfTurn(Minion *thisMinion, Minion *opponentMinion, Player *actPlayer, Player *inactPlayer);
    void endOfTurn(Minion *thisMinion, Minion *opponentMinion, Player *actPlayer, Player *inactPlayer);
    void minionEnter(Minion *thisMinion, Minion *opponentMinion, Player *actPlayer, Player *inactPlayer);
    void minionLeave(Minion *thisMinion, Minion *opponentMinion, Player *actPlayer, Player *inactPlayer);
};

class ActivatedAbility: public Ability {
  // name is inherited from the parent class
  public:   
    ActivatedAbility(const std::string& nameOfAbility);
    void performAbility(std::string what, int minionNum, Minion *minion, Player *actPlayer, Player *inactPlayer) override;
    void performAbility(std::string what, int minionNum, Ritual *ritual, Player *actPlayer, Player *inactPlayer) override;
};

#endif

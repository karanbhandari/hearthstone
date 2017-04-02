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
    virtual void performTriggeredAbility(std::string what);
    virtual ~Ability();
};

class TriggeredAbility: public Ability {
	// name is inherited from the parent class
	public: 	
    TriggeredAbility(const std::string& nameOfAbility);
    void performAbility(std::string what, int minionNum, Minion *minion, Player *actPlayer, Player *inactPlayer)  override;
    void performAbility(std::string what, int minionNum, Ritual *ritual, Player *actPlayer, Player *inactPlayer) override;
    void startOfTurn();
    void endOfTurn();
    void minionEnter();
    void minionLeave();
};

class ActivatedAbility: public Ability {
  // name is inherited from the parent class
  public:   
    ActivatedAbility(const std::string& nameOfAbility);
    void performAbility(std::string what, int minionNum, Minion *minion, Player *actPlayer, Player *inactPlayer) override;
    void performAbility(std::string what, int minionNum, Ritual *ritual, Player *actPlayer, Player *inactPlayer) override;
};

#endif

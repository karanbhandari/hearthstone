#ifndef __ABILITY_H__
#define __ABILITY_H__

#include <string>
#include <sstream>
#include <iostream>

class Ability {
	 std::string name;

  public:
    Ability(const std::string& nameOfAbility);
    virtual void performAbility ();
    virtual ~Ability() = 0;
};

class TriggeredAbility: public Ability {
	// name is inherited from the parent class
	public: 	
    TriggeredAbility(const std::string& nameOfAbility);
    void performAbility() override;
    void startOfTurn();
    void endOfTurn();
    void minionEnter();
    void minionLeave();
}

class ActivatedAbility: public Ability {
  // name is inherited from the parent class
  public:   
    ActivatedAbility(const std::string& nameOfAbility);
    void performAbility() override;
}

#endif

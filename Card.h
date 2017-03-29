#include <string>
#include <sstream>
#include <iostream>
#include "Player.h"
#include "Ability.h"

// this is an abstract cards class that if a parent to Minions, spells and encahntments
class Card {
  public:
	  Card();
	  virtual ~Card() = 0;
};

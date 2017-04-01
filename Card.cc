#include <iostream>
#include <string>
#include "Card.h"
#include "Player.h"

using namespace std;

//Card::Card() {};

// Creates a new card specific to the name of the card given
Card::Card(string name) : name{name} {
}

void Card::addToBoard(Card *ritualSlot, Card *minion, Slot *slot) {}

Card::~Card() {}

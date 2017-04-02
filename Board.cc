#include <vector>
#include <iostream>

#include "Board.h"

using namespace std;


// TODO: add support for views
// Board Ctor
Board::Board(Player *p1, Player *p2) : p1{p1}, p2{p2} {	
}

// TODO: add support for deleting views
//BOARD Dtor
Board::~Board() {
	delete p1;
	delete p2;
}
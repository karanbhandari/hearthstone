#ifndef __BOARD_H__
#define __BOARD_H__

#include <vector>
#include <iostream>

//#include "View.h"
#include "Player.h"

class Board{
//	std::vector<View *> views;
public:
	Player* p1;
	Player *p2;
	Board(Player *p1, Player *p2);
//	void notifyViews();
	~Board();
};


#endif
/*
 * Print.h
 *
 *  Created on: Apr 3, 2017
 *      Author: Acer User
 */

#ifndef PRINT_H_
#define PRINT_H_

#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "ascii_graphics.h"
#include "Player.h"
#include "Card.h"
#include "Minion.h"
#include "Board.h"
#include "Ability.h"
#include "Spells.h"

void pushMinion(std::vector<card_template_t> * list, Minion* minion);
void pushRitual(std::vector<card_template_t> * list, Ritual* ritual);
void pushEmptyCard(std::vector<card_template_t> * list);
void printBoard(Player *p1, Player* p2);


#endif /* PRINT_H_ */

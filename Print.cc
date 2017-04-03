#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include "ascii_graphics.h"
#include "Print.h"
using namespace std;

void pushMinion(vector<card_template_t> * list, Minion* minion) {
	if (minion == nullptr) {
		list->push_back(CARD_TEMPLATE_BORDER);
	} else if (!minion->hasAbility()) {
		list->push_back(
				display_minion_no_ability(minion->getName(), minion->getCost(),
						minion->getAttack(), minion->getDefence()));
	} else if (minion->hasTriggeredAbility()) {
		list->push_back(
				display_minion_triggered_ability(minion->getName(),
						minion->getCost(), minion->getAttack(),
						minion->getDefence(), minion->getAbility()->getName()));
	} else {
		list->push_back(
		// gotta edit cost of ability.
				display_minion_activated_ability(minion->getName(),
						minion->getCost(), minion->getAttack(),
						minion->getDefence(), 1,
						minion->getAbility()->getName()));
	}
}

void pushRitual(vector<card_template_t> * list, Ritual* ritual) {
	list->push_back(
			display_ritual(ritual->getName(), ritual->getCost(),
					ritual->getActivateCost(), ritual->getAbility()->getName(),
					ritual->getCharge()));
}

void pushEmptyCard(vector<card_template_t> * list) {
	list->push_back(CARD_TEMPLATE_BORDER);
}

void printBoard(Player *p1, Player* p2) {

	// Creating variables needed for function
	vector<vector<card_template_t>> myBoard;
	vector<card_template_t> POneMinionList;
	vector<card_template_t> * P1MinionPointer = &POneMinionList;
	vector<card_template_t> PTwoMinionList;
	vector<card_template_t> * P2MinionPointer = &PTwoMinionList;
	vector<card_template_t> playerOneBackLine;
	vector<card_template_t> * P1ListPointer = &playerOneBackLine;
	vector<card_template_t> playerTwoBackLine;
	vector<card_template_t> * P2ListPointer = &playerTwoBackLine;
	vector<card_template_t> currentRow;
	card_template_t currentCard;
	string outputLine;
	string horiBoarder =
			"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------";
	int dummyLine = 0;
	int p1SlotSize = p1->getSlot()->numOfCards();
	int p2SlotSize = p2->getSlot()->numOfCards();
	Minion * p1GraveMinion = static_cast<Minion*> (p1->getGraveyard()->showTopCard());
	Minion * p2GraveMinion = static_cast<Minion*> (p2->getGraveyard()->showTopCard());
	Ritual * p1Ritual = (Ritual *)p1->getRitual();
	Ritual * p2Ritual = (Ritual *)p2->getRitual();
	Slot * p1Slot = p1->getSlot();
	Slot * p2Slot = p2->getSlot();

	// Player One Back Row -----------------------------------------------------------------------------------------------
	// Player One Ritual Card
	if (p1Ritual != nullptr)
		pushRitual(P1ListPointer, p1Ritual);
	else
		pushEmptyCard(P1ListPointer);
	// Empty Space
	playerOneBackLine.push_back(CARD_TEMPLATE_EMPTY);
	// Player One Card
	playerOneBackLine.push_back(
			display_player_card(1, p1->getName(), p1->life, p1->getMagic()));
	// EmptySpace
	playerOneBackLine.push_back(CARD_TEMPLATE_EMPTY);
	// Player One Graveyard
	pushMinion(P1ListPointer, p1GraveMinion);

	// Player Two Back Row ------------------------------------------------------------------------------------------------
	// Player Two Ritual Card
	if (p1Ritual != nullptr)
		pushRitual(P2ListPointer, p2Ritual);
	else
		pushEmptyCard(P2ListPointer);
	// Empty Space
	playerTwoBackLine.push_back(CARD_TEMPLATE_EMPTY);
	// Player Two Card
	playerTwoBackLine.push_back(
			display_player_card(2, p2->getName(), p2->life, p2->getMagic()));
	// EmptySpace
	playerTwoBackLine.push_back(CARD_TEMPLATE_EMPTY);
	// Player Two Graveyard
	pushMinion(P2ListPointer, p2GraveMinion);

	Minion * dummyMinion;
	// Player One Minion Row
	for (int i = 0; i < 5; i++) {
		if (i >= p1SlotSize)
			pushEmptyCard(P1MinionPointer);
		else{
			dummyMinion = static_cast<Minion*> (p1Slot->getIth(i));
			pushMinion(P1MinionPointer, dummyMinion);
		}
	}

	// Player Two Minion Row
	for (int i = 0; i < 5; i++) {
		if (i >= p2SlotSize)
			pushEmptyCard(P2MinionPointer);
		else{
			dummyMinion = static_cast<Minion*> (p2Slot->getIth(i));
			pushMinion(P2MinionPointer, dummyMinion);
		}

	}

	// General Board pushing
	myBoard.push_back(playerOneBackLine);
	myBoard.push_back(POneMinionList);
	myBoard.push_back(PTwoMinionList);
	myBoard.push_back(playerTwoBackLine);

	// Prints the Board in command Line
	cout << horiBoarder << endl;
	for (int line = 0; line < 5; line++) {
		if (line == 2) {
			// Prints centre graphic
			for (int i = 0; i < 10; i++) {
				outputLine = CENTRE_GRAPHIC[i];
				cout << outputLine << "\n";
			}
		} else {
			currentRow = myBoard[dummyLine];
			for (int i = 0; i < 11; i++) {
				cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
				for (int cardNum = 0; cardNum < 5; cardNum++) {
					currentCard = currentRow[cardNum];
					outputLine = currentCard[i];
					cout << outputLine;
				}
				cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
				cout << "\n";
			}
			for (int j = 0; j < 5; j++) {
				currentRow.pop_back();
			}
			dummyLine++;
		}
	}
	cout << horiBoarder << endl;
}

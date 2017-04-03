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
	cout << " I started running";
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
	Minion *p1GraveMinion = nullptr;
	Minion *p2GraveMinion = nullptr;
	if (p1->getGraveyard()->numOfCards() > 0)
		p1GraveMinion = dynamic_cast<Minion*> (p1->getGraveyard()->showTopCard());
	if(p2->getGraveyard()->numOfCards() > 0)
		p2GraveMinion = dynamic_cast<Minion*> (p2->getGraveyard()->showTopCard());
	Ritual * p1Ritual = p1->getRitual();
	Ritual * p2Ritual = p2->getRitual();
	Slot * p1Slot = p1->getSlot();
	Slot * p2Slot = p2->getSlot();

	cout << "all variables initiated" << endl;

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

	cout << "Checkpoint 1" << endl;

	// Player Two Back Row ------------------------------------------------------------------------------------------------
	// Player Two Ritual Card
	if (p2Ritual != nullptr)
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

	cout << "Checkpoint 2" << endl;

	Minion * dummyMinion;
	// Player One Minion Row
	for (int i = 1; i <= 5; i++) {
		cout << "in " << p1SlotSize << endl;
		if (i > p1SlotSize)
			pushEmptyCard(P1MinionPointer);
		else{
			dummyMinion = nullptr;
			cout << "Number of minions on Slots : " << p1Slot->numOfCards() << endl;
			if(p1Slot->numOfCards() > 0 && p1Slot->getIth(i))
				dummyMinion = dynamic_cast<Minion*> (p1Slot->getIth(i));
			cout << "gets here" << endl;
			pushMinion(P1MinionPointer, dummyMinion);
		}
	}
	cout << "Checkpoint 3" << endl;

	// Player Two Minion Row
	for (int i = 1; i <= 5; i++) {
		if (i > p2SlotSize)
			pushEmptyCard(P2MinionPointer);
		else{
			dummyMinion = nullptr;
			cout << "Number of minions on Slots : " << p2Slot->numOfCards() << endl;
			if (p2Slot->numOfCards() > 0 && p2Slot->getIth(i))
				dummyMinion = dynamic_cast<Minion*> (p2Slot->getIth(i));
			pushMinion(P2MinionPointer, dummyMinion);
		}

	}
	cout << "Checkpoint 4" << endl;

	// General Board pushing
	myBoard.push_back(playerOneBackLine);
	myBoard.push_back(POneMinionList);
	myBoard.push_back(PTwoMinionList);
	myBoard.push_back(playerTwoBackLine);

	cout << "Checkpoint 5" << endl;

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
	cout << "Checkpoint 6" << endl;

}

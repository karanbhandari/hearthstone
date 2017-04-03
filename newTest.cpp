#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include "ascii_graphics.h"
using namespace std;

int main() {
	cout << "Iteration 3" << endl; // prints !!!Hello World!!!

	// Creating card objects
	vector<vector<card_template_t>> myBoard;
	vector<card_template_t> POneMinionList;
	vector<card_template_t> PTwoMinionList;
	vector<card_template_t> playerOneBackLine;
	vector<card_template_t> playerTwoBackLine;
	vector<card_template_t> currentRow;
	card_template_t currentCard;
	string outputLine;
	string horiBoarder =
			"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------";
	int dummyLine = 0;

	// Player One Back Row
	playerOneBackLine.push_back(
			display_ritual("Aura of Power", 1, 1,
					"Whenever a minion enters play under your control, it gains +1/+1",
					1));
	playerOneBackLine.push_back(CARD_TEMPLATE_EMPTY);
	playerOneBackLine.push_back(display_player_card(1, "Sean", 20, 0));
	playerOneBackLine.push_back(CARD_TEMPLATE_EMPTY);
	playerOneBackLine.push_back(
			display_minion_triggered_ability("Bone Golem", 2, 2, 1,
					"Gain +1/+1 whenever a minion leaves play."));

	// Player Two Back Row
	playerTwoBackLine.push_back(
			display_ritual("Aura of Power", 1, 1,
					"Whenever a minion enters play under your control, it gains +1/+1",
					1));
	playerTwoBackLine.push_back(CARD_TEMPLATE_EMPTY);
	playerTwoBackLine.push_back(display_player_card(2, "Peter", 17, 0));
	playerTwoBackLine.push_back(CARD_TEMPLATE_EMPTY);
	playerTwoBackLine.push_back(
			display_minion_triggered_ability("Bone Golem", 2, 2, 1,
					"Gain +1/+1 whenever a minion leaves play."));

	// Player One Minion Row
	POneMinionList.push_back(display_minion_no_ability("Monster 1", 1, 2, 3));
	POneMinionList.push_back(display_minion_no_ability("Monster 2", 1, 2, 3));
	POneMinionList.push_back(display_minion_no_ability("Monster 3", 1, 2, 3));
	POneMinionList.push_back(display_minion_no_ability("Monster 4", 1, 2, 3));
	POneMinionList.push_back(display_minion_no_ability("Monster 5", 1, 2, 3));

	// Player Two Minion Row
	PTwoMinionList.push_back(display_minion_no_ability("Monster 1", 1, 2, 3));
	PTwoMinionList.push_back(display_minion_no_ability("Monster 2", 1, 2, 3));
	PTwoMinionList.push_back(display_minion_no_ability("Monster 3", 1, 2, 3));
	PTwoMinionList.push_back(display_minion_no_ability("Monster 4", 1, 2, 3));
	PTwoMinionList.push_back(display_minion_no_ability("Monster 5", 1, 2, 3));

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

	/*
	 // Prints second half of board
	 for (int line = 0; line < 2; line++) {
	 currentRow = myBoard[dummyLine];
	 for (int i = 0; i < 11; i++) {
	 for (int cardNum = 0; cardNum < 5; cardNum++) {
	 currentCard = currentRow[cardNum];
	 outputLine = currentCard[i];
	 cout << outputLine;
	 }
	 cout << "\n";
	 }
	 for (int j = 0; j < 5; j++){
	 currentRow.pop_back();
	 }
	 dummyLine++;
	 }
	 */
	return 0;
}

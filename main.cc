#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#define dbg true
#include "Board.h"
#include "Print.h"

using namespace std;

void mainLoop(istream *in, bool testing, Board* board, Player *activePlayer) {
	string s;
	int i, j, k;
	Player *inactivePlayer = nullptr;
	if (activePlayer == board->p1) {
		inactivePlayer = board->p2;
	} else {
		inactivePlayer = board->p1;
	}
	while (true) {
		if(!getline(*in, s))
			break;
		istringstream iss{s};
		iss >> s;
		if (s == "end") { // end players turn
			cout << "Next Player's turn." << endl;
			activePlayer->performEndTrigger(activePlayer, inactivePlayer);
			inactivePlayer = activePlayer;
			if (activePlayer == board->p1) {
				activePlayer = board->p2;
			} else {
				activePlayer = board->p1;
			}
			activePlayer->performStartTrigger(activePlayer, inactivePlayer);
		} else if (s == "quit") { // end the game with no winner
			cout << "Quitting" << endl;
			delete board;
			break;
		} else if (s == "draw") { // draws a card (only in testing mode) 
			if (testing) {
				// cout << "draw" << endl;
				activePlayer->draw();
			} else { 
				cout << "testing should be enabled for this command" << endl;
			}
		} else if (s == "discard") { // remove ith card from the players hand (only in Tmode)
			iss >> i;
			if (testing) {
				// cout << "discard " << i << endl;
				activePlayer->discard(i);
			} else { 
				cout << "testing should enabled for this command" << endl;
			} 
		} else if (s ==  "attack") { // attack the opponent
			iss >> i; // active players minion
			if (iss >> j) { // attack the minion j of opposition
				// cout << "attack on " << j << " by " << i << endl;
				activePlayer->attack(i, inactivePlayer, j, activePlayer);
			} else { // attack on the opposite player
				iss.clear();
				// cout << "attack on player by " << i << endl;
				activePlayer->attack(i, inactivePlayer);
			}
		} else if (s == "play") { // to play a card i
			iss >> i;
			int l;
			if (iss >> j) {
				if(! (iss >> l)) {
					iss.clear();
					l = 114;
				}
				// cout << "play " << i << "th card on player " << j << "s " << l << endl;
				if(j == 1) {
					activePlayer->play(i, board->p1, l, activePlayer, inactivePlayer);
				} else {
					activePlayer->play(i, board->p2, l, activePlayer, inactivePlayer);
				}
			} else {
				iss.clear();
				// cout << "play " << i << "the card" << endl;
				activePlayer->play(i, activePlayer, inactivePlayer);
			}
		} else if (s == "use") { // use activated ability 
			iss >> i;
			if (iss >> j) {
				iss >> k;
				// cout << "use " << i << "th minion on player " << j << "s " << k << endl;
				if(j == 1) {
					activePlayer->use(i, board->p1, k, activePlayer, inactivePlayer);
				} else {
					activePlayer->use(i, board->p2, k, activePlayer, inactivePlayer);
				}
			} else {
				// cout << "use " << i << "the minion" << endl;
				iss.clear();
				activePlayer->use(i, activePlayer, inactivePlayer);
			}
		} else if (s == "inspect") { // inspect the ith minion owned by the player
			iss >> i;
			// cout << "inspect the " << i << "th minion" << endl;
		} else if (s == "hand") { //display the activePlayers Hand
			// cout << "hand of active" << endl;
			activePlayer->showHand();
			printHand(activePlayer);
		} else if (s == "board") { //display the board
			// cout << "wrong command" << endl;
			printBoard(activePlayer, inactivePlayer);
			//activePlayer->showDeck();
		} else {
			cout << "INVALID COMMAND" << endl;
		}
		// if(dbg) cout << inactivePlayer->getName() << "s life: " <<inactivePlayer->life <<endl;
		activePlayer->moveToGraveyard();
		if (!inactivePlayer->isAlive()) {
			cout << inactivePlayer->getName() << " loses" <<endl;
			break;
		}
	}
}


int main (int argc, char *argv[]) {
	string deck1 = "default.deck", deck2 = "default.deck", init = "", p1 = "p1", p2 = "p2";
	bool testing;
	for (int i = 1; i < argc; i++) { 
		string theArg = argv[i];
		if (theArg == "-deck1") { //to get deck1 name 
			deck1 = argv[i+1];
		} else if (theArg == "-deck2") { //to get deck2 name
			deck2 = argv[i+1];		
		} else if (theArg == "-init") { // to get init fileName
			init = argv[i+1];
		} else if (theArg == "-testing") { // to see if testing is enabled
			testing = true;
		}
	}
	ifstream *deck1P = new ifstream(deck1.c_str());
	ifstream *deck2P = new ifstream(deck2.c_str());
	cout << "Enter Player 1's Name: " << endl;
		cin >> p1;
	cout << "Enter Player 2's Name: " << endl;
		cin >> p2;
	Board *b = new Board{new Player{p1, deck1P}, new Player{p2, deck2P}};
	Player *activePlayer = b->p1;
	if(init != "") {
		istream *in = new ifstream(init.c_str());
		mainLoop(in, testing, b, activePlayer);
		delete in;
	} 
	mainLoop(&cin, testing, b, activePlayer);	
	delete deck1P;
	delete deck2P;
	return 0;
}	

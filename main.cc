#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

void mainLoop(istream *in, bool testing, Board* board, Player *activePlayer) {
	string s;
	int i, j, k;
	player *inactivePlayer = nullptr;
	if (activePlayer == board->p1) {
		inactivePlayer = board->p2;
	} else {
		inactivePlayer = board->p1;
	}
	while (true) {
		getline(*in, s);
		istringstream iss{s};
		iss >> s;
		if (s == "end") { // end players turn
			cout << s << endl;
			activePlayer->end();
			inactivePlayer = activePlayer;
			if (activePlayer == board->p1) {
				activePlayer = board->p2;
			} else {
				activePlayer = board->p1;
			}
			activePlayer->start();
		} else if (s == "quit") { // end the game with no winner
			cout << "quit" << endl;
			delete board;
			break;
		} else if (s == "draw") { // draws a card (only in testing mode) 
			if (testing) {
				cout << "draw" << endl;
				activePlayer->draw();
			} else { 
				cout << "testing should be enabled for this command" << endl;
			}
		} else if (s == "discard") { // remove ith card from the players hand (only in Tmode)
			iss >> i;
			if (testing) {
				cout << "discard " << i << endl;
				activePlayer->discard(i);
			} else 
				cout << "testing should enabled for this command" << endl;
			} 
		} else if (s ==  "attack") { // attack the opponent
			iss >> i; // active players minion
			if (iss >> j) { // attack the minion j of opposition
				cout << "attack on " << j << " by " << i << endl;
				activePlayer->attack(i, inactivePlayer, j);
			} else { // attack on the opposite player
				iss.clear();
				cout << "attack on player by " << i << endl;
				activePlayer->attack(i, inactivePlayer);
			}
		} else if (s == "play") { // to play a card i
			iss >> i;
			if (iss >> j) {
				iss >> k;
				cout << "play " << i << "th card on player " << j << "s " << j << endl;
				if(j == 1) {
					activePlayer->play(i, board->p1, j);
				} else {
					activePlayer->play(i, board->p2, j);
				}
			} else {
				iss.clear();
				cout << "play " << i << "the card" << endl;
				activePlayer->play(i);
			}
		} else if (s == "use") { // use activated ability 
			iss >> i;
			if (iss >> j) {
				iss >> k;
				cout << "use " << i << "th minion on player " << j << "s " << j << endl;
				if(j == 1) {
					activePlayer->use(i, board->p1, j);
				} else {
					activePlayer->use(i, board->p2, j);
				}
			} else {
				cout << "use " << i << "the minion" << endl;
				iss.clear();
				activePlayer->use(i);
			}
		} else if (s == "inspect") { // inspect the ith minion owned by the player
			iss >> i;
			cout << "inspect the " << i << "th minion" << endl;
		} else if (s == "hand") { //display the activePlayers Hand
			cout << "hand of active" << endl;
		} else if (s == "board") { //display the board
			cout << "wrong command" << endl;
		} else {
			cout << "INVALID COMMAND" << endl;
		}
		//board->notifyViews();
		if(!inactivePlayer->isAlive()) {
			cout << inactivePlayer->getName() << " loses" <<endl;
		}
	}
}


int main (int argc, char *argv[]) {
	string deck1 = "default.deck", deck2 = "default.deck", init = "";
	bool testing;
	Board *b = new Board{new player{"p1"}, new player{"p2"}};
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
	if(init != "") {
		istream *in = new ifstream(init.c_str());
		mainLoop(in, testing);
		delete in;
	} 
	mainLoop(&cin, testing);	
	return 0;
}	

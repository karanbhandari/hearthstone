#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

void mainLoop(istream *in, bool testing) {
	string s;
	int i, j, k;
	while (true) {
		getline(*in, s);
		istringstream iss{s};
		iss >> s;
		if (s == "end") { // end players turn
			cout << s << endl;
		} else if (s == "quit") { // end the game with no winner
			cout << "quit" << endl;
			break;
		} else if (s == "draw") { // draws a card (only in testing mode) 
			if (testing)
				cout << "draw" << endl;
			else 
				cout << "testing should be enabled for this command" << endl;
		} else if (s == "discard") { // remove ith card from the players hand (only in Tmode)
			iss >> i;
			if (testing)
				cout << "discard " << i << endl;
			else 
				cout << "testing should enabled for this command" << endl;
		} else if (s ==  "attack") { // attack the opponent
			iss >> i; // active players minion
			if (iss >> j) { // attack the minion j of opposition
				cout << "attack on " << j << " by " << i << endl;
			} else { // attack on the opposite player
				iss.clear();
				cout << "attack on player by " << i << endl;
			}
		} else if (s == "play") { // to play a card i
			iss >> i;
			if (iss >> j) {
				iss >> k;
				cout << "play " << i << "th card on player " << j << "s " << j << endl;
			} else {
				cout << "play " << i << "the card" << endl;
				iss.clear();
			}
		} else if (s == "use") { // use activated ability 
			iss >> i;
			if (iss >> j) {
				iss >> k;
				cout << "use " << i << "th minion on player " << j << "s " << j << endl;
			} else {
				cout << "use " << i << "the minion" << endl;
				iss.clear();
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

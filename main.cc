#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main (int argc, char *argv[]) {
	string s;
	int i, j, k;
	while (true) {
		getline(cin, s);
		istringstream iss{s};
		iss >> s;
		if (s == "end") { // end players turn
			cout << s << endl;
		} else if (s == "quit") { // end the game with no winner
			cout << "quit" << endl;
			break;
		} else if (s == "draw") { // draws a card (only in testing mode) 
			cout << "draw" << endl;
		} else if (s == "discard") { // remove ith card from the players hand (only in Tmode)
			cin >> i;
			cout << "discard " + i << endl;
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
				cout << "use " << i << "th card on player " << j << "s " << j << endl;
			} else {
				cout << "minion " << i << "the minion" << endl;
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
	return 0;
}	

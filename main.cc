#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main (int argc, char *argv[]) {
	string s;
	while (true) {
		getline(cin, s);
		istringstream iss{s};
		iss >> s;
		if (s == "end") { // end players turn
			cout << s << endl;
		} else if (s == "quit") { // end the game with no winner
			cout << "quit" << endl;
		} else if (s == "draw") { // draws a card (only in testing mode) 
			cout << "draw" << endl;
		} else if (s == "discard") { // remove ith card from the players hand (only in Tmode)
			cin >> i;
			cout << "discard " + i << endl;
		} else if (s ==  "attack") { // attack the opponent
			ss >> i; // active players minion
			if (ss >> j) { // attack the minion j of opposition
				cout << "attack on " << j << " by " << i << endl;
			} else { // attack on the opposite player
				ss.clear();
				cout << "attack on player by " << i << endl;
			}
		} else if (s == "play") { // to play a card i
			ss >> i;
			if (ss >> j) {
				ss >> k;
				cout << "play " << i << "th card on player " << j << "s " << j << end;
			} else {
				cout << "play " << i << "the card" << endl;
				ss.clear();
			}
		} else if (s == "use") { // use activated ability 
			ss >> i;
			if (ss >> j) {
				ss >> k;
				cout << "use " << i << "th card on player " << j << "s " << j << end;
			} else {
				cout << "minion " << i << "the minion" << endl;
				ss.clear();
			}
		} else if (s = "describe") { 
	}
}	

#include <string>
#include <sstream>
#include <iostream>
#include "Deck.h"
#include "Card.h"

using namespace std;


// returns the card on the top of the deck and removes it from the deck
Card* AbstractDeck::getTopCard() {
	Card *temp = cardList.back();
	cardList.pop_back();
	return temp;
}


// returns ith card on the list 
Card* AbstractDeck::getIthCard(int i) {
	return cardList[i - 1];
}

// removes the ith card from the list
void AbstractDeck::removeCard(int i) {
	cardList.erase(cardList.begin() + (i - 1));
}

//deletes the card from the list
void AbstractDeck::deleteCard(int i) {
	Card *temp = cardList[i];
	removeCard(i);
	delete temp;
}

// adds the card to the list
void AbstractDeck::addCard(Card* card) {
	cardList.emplace_back(card);
}


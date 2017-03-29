#ifndef DECK_H_
#define DECK_H_

#include <string>
#include <iostream>
#include <vector>

#include "Card.h"

class AbstractDeck {
	int size;
	std::vector<Card *> cardList;
	public:
	AbstractDeck(std::vector<Card *> cardList);
	~AbstractDeck() = 0;
	void shuffle();
	Card* getTopCard();
	Card* getIthCard(int i);
	void removeCard(int i);
	void deleteCard(int i);
};

class Deck: public AbstractDeck {
	public:
	Deck(std::vector<Card *> cardList);
	~Deck();
};

class Slot: public AbstractDeck {
	public:
	Slot(std::vector<Card *> cardList);
	~Slot();
};

class Hand: public AbstractDeck {
	public:
	Hand(std::vector<Card *> cardList);
	~Hand();
};

class Graveyard: public AbstractDeck {
	public:
	Graveyard(std::vector<Card *> cardList);
	~Graveyard();
};

#endif
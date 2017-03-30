#ifndef DECK_H_
#define DECK_H_

#include <string>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Cards.h"

class AbstractDeck {
protected:
	int size;
	std::vector<Cards *> cardList;
public:
	AbstractDeck();
	virtual ~AbstractDeck() = 0;
	Cards* getTopCard();
	Cards* getIthCard(int i);
	void removeCard(int i);
	void deleteCard(int i);
	void addCard(Cards *card);
	bool isEmpty();
};

class Deck: public AbstractDeck {
public:
	Cards * createCard (std::string name);
	Deck(std::istream deckList);
	~Deck();
	virtual void shuffle();
};

class Slot: public AbstractDeck {
public:
	Slot();
	~Slot();
};

class Hand: public AbstractDeck {
public:
	Hand(Deck* deck);
	~Hand();
};

class Graveyard: public AbstractDeck {
public:
	Graveyard();
	~Graveyard();
};

#endif

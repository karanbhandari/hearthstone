#ifndef DECK_H_
#define DECK_H_

#include <string>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Card.h"

class AbstractDeck {
protected:
	int size;
	std::vector<Card *> cardList;
public:
	AbstractDeck();
	virtual ~AbstractDeck() = 0;
	Card* getTopCard();
	Card* getIthCard(int i);
	void removeCard(int i);
	void deleteCard(int i);
	void add(Card *card);
	bool isEmpty();
};

class Deck: public AbstractDeck {
public:
	Card * createCard (std::string name);
	Deck(std::istream deckList);
	~Deck();
	virtual void shuffle();
};

class Slot: public AbstractDeck {
public:
	Slot();
	~Slot();
	void add(Card *card, int i); // TODO: @Karan Might not be needed
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

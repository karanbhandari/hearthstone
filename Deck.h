#ifndef DECK_H_
#define DECK_H_

#include <string>
#include <iostream>
#include <vector>

class Card;

class AbstractDeck {
	int size;
	std::vector<Card *> cardList;
	public:
	AbstractDeck();
	virtual ~AbstractDeck() = 0;
	Card* getTopCard();
	Card* getIthCard(int i);
	void removeCard(int i);
	void deleteCard(int i);
	void addCard(Card *card);
	bool isEmpty();
};

class Deck: public AbstractDeck {
	public:
	Deck();
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
	Hand();
	~Hand();
};

class Graveyard: public AbstractDeck {
	public:
	Graveyard();
	~Graveyard();
};

#endif

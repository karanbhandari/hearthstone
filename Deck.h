#ifndef DECK_H_
#define DECK_H_

#include <string>
#include <iostream>
#include <vector>

class Card;
class Minion;

class AbstractDeck {
protected:
	int size;
	std::vector<Card *> cardList;
public:
	AbstractDeck(int size);
	virtual ~AbstractDeck() = 0;
	Card* getTopCard();
	Card* getIth(int i);
	void remove(int i);
	void deleteCard(int i);
	void add(Card *card);
	bool isEmpty();
	void show();
};

class Deck: public AbstractDeck {
public:
	Card * createCard (std::string name);
	Deck(std::istream &deckList);
	~Deck();
	virtual void shuffle();
};

class Slot: public AbstractDeck {
public:
	Slot();
	~Slot();
	void add (Minion *minion); // TODO: need to implement this shit
	void add(Card *card, int i); // TODO: @Karan Might not be needed
	void changeValOfCards(int attack, int defence);
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

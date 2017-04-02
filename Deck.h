#ifndef DECK_H_
#define DECK_H_

#include <string>
#include <iostream>
#include <vector>

class Card;
class Minion;
class Player;

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
  virtual void addMinion(Card *minion);
	bool isEmpty();
	void show();
	int numOfCards();
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
	void performStartTrigger(Player *p1, Player *p2);
	void performEndTrigger(Player *p1, Player *p2);
	void performMinionEnter(Minion *minion, Player *p1, Player *p2);
	void performMinionLeave(Minion *minion, Player *p1, Player *p2);
	void add(Minion *minion); // TODO: need to implement this shit
  	void addMinion (Card *minion) override;
 // Not being used anymore @Karan
 // void add(Card *card, int i); // TODO: @Karan Might not be needed
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
	void popTop();
};

#endif

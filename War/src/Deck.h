/*
 * Deck.h
 *
 *  Created on: Nov 11, 2014
 *      Author: williamhooper
 */

#ifndef DECK_H_
#define DECK_H_

#include <vector>

#include "Card.h"
#include "Player.h"

#define MaxCards 52

class Deck {
public:
	Deck();
	virtual ~Deck();

	/**
	 * Shuffle the deck and reset the next available card to the beginning of the deck
	 */
	void shuffle();

	/**
	 * Return true if the deck is empty (next available card is past the end of the deck)
	 */
	bool isEmpty() const;

	/**
	 * Draw a card from the deck
	 */
	const Card draw();

	void error(std::string s);

private:
	unsigned nextCard;
	std::vector<Card> cardDeck;
};

#endif /* DECK_H_ */

/*
 * Card.h
 *
 *  Created on: Nov 11, 2014
 *      Author: williamhooper
 */

#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include <string>

/**
 * String constants for the suits
 */
static const std::string suitNames[] =
		{ "Spades", "Hearts", "Diamonds", "Clubs" };

/**
 * String constants for the rank
 */
static const std::string rankNames[] = { "Joker", "Two", "Three", "Four",
		"Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King",
		"Ace" };

class Card {
public:
	/**
	 * Suit enumerations
	 */
	enum Suit
	{
		Spades = 0, Hearts, Diamonds, Clubs
	};

	/**
	 * Rank enumerations ordered by value for game of war
	 */
	enum Rank
	{
		Joker = 0,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		Jack,
		Queen,
		King,
		Ace
	};

	Card(Suit s, Rank r);

	virtual ~Card()
	{

	}

	/**
	 * Get a special joker card. This is given to the player going first
	 */
	static const Card getJoker()
	{
		return Card(Spades, Joker);
	}

	/**
	 * Return true if this card is a joker
	 */
	bool isJoker() const
	{
		return (cardRank == Joker);
	}

	/**
	 * Output the card to an output stream as "rank of suit"
	 */
	friend std::ostream& operator <<(std::ostream&, const Card&);

	/**
	 * Compare operators. For the game of war we only care about the rank
	 */
	friend bool operator ==(const Card &lhs, const Card &rhs);
	friend bool operator <(const Card &lhs, const Card &rhs);
private:
	Suit cardSuit;
	Rank cardRank;
};

#endif /* CARD_H_ */

/*
 * Player.h
 *
 *  Created on: Nov 11, 2014
 *      Author: williamhooper
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>

#include "Card.h"

class Player {
public:
	/**
	 * Deconstructor
	 */
	virtual ~Player() {}

	/**
	 * Play a card. If the player receives a joker then this player is going first
	 */
	virtual const Card playCard(const Card opponentCard) = 0;

	/**
	 * Receive a card from the dealer
	 */
	void receiveCard(const Card c)
	{
		hand.push_back(c);
	}

	/**
	 * Add points to the score
	 */
	void addScore(int s)
	{
		score += s;
	}

	/**
	 * Get the score
	 */
	int getScore() const
	{
		return score;
	}

	/**
	 * Return true if the player has cards in the hand
	 */
	bool hasCards() const
	{
		return (hand.size() != 0);
	}

	/**
	 * Receive the cards played from the previous round. This member function would
	 * be used by a computer player that may need to 'see' what cards were played.
	 */
	void cardsPlayed(const Card card1, const Card card2) {}

protected:
	/**
	 * Constructor
	 */
	Player() :
			score(0) {
	}

	int score;
	std::vector<Card> hand;
};

#endif /* PLAYER_H_ */

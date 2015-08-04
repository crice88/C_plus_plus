/*
 * Card.cpp
 *
 *  Created on: Nov 11, 2014
 *      Author: williamhooper
 */

#include "Card.h"

/**
 * Constructor
 */
Card::Card(Suit s, Rank r) : cardSuit(s), cardRank(r)
{

}


std::ostream& operator <<(std::ostream& os, const Card& c)	// Overrides ostream to display a card ( Suit, Rank )
{
	return (os << rankNames[c.cardRank] << " of "<< suitNames[c.cardSuit] );
}

bool operator ==(const Card &lhs, const Card &rhs)	// Check for equality
{
	int lhrank = lhs.cardRank;	// Ranks and Suits converted to int representation, then compared
	int rhrank = rhs.cardRank;

	if((lhrank == rhrank))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator <(const Card &lhs, const Card &rhs)	// Check for inequality
{
	int lhrank = lhs.cardRank;	// Ranks and suits converted to int representation, then compared
	int rhrank = rhs.cardRank;

	if((lhrank < rhrank))
	{
		return true;
	}
	else
	{
		return false;
	}
}

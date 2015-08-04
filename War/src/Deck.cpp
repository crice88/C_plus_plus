/*
 * Deck.cpp
 *
 *  Created on: Nov 11, 2014
 *      Author: williamhooper
 */

#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

Deck::Deck() : nextCard(0)	// nextCard used as a counter to know how many cards are in the deck (0 = full deck)
{
	for(int suitIterator = 0; suitIterator < 4; suitIterator++)	// Starts at the first suit and adds each rank of that suit to the deck
	{
		for(int rankIterator = 1; rankIterator < 14; rankIterator++)	// Iterates through all ranks
		{
			cardDeck.push_back(Card(Card::Suit(suitIterator), Card::Rank(rankIterator)));
		}
	}
}

void Deck::shuffle()	// Uses algorithm to perform a random shuffle of the elements in the vector
{
	int randNumber = (rand() % 25);	// Mixes up the different shuffles, only shuffling once gave the same deck every time
	for(int i = 0; i < randNumber; i++ )
	{
		std::random_shuffle (cardDeck.begin(), cardDeck.end());
	}
	nextCard = 0;
}

bool Deck::isEmpty() const	// Checks to see if the deck is empty (52 = empty desk)
{
	return (nextCard == 52);
}

const Card Deck::draw()	// Returns next available card in the vector
{
	if(nextCard == 52) error("Out of Range!!");	// Throws error if out of range
	Card c = cardDeck[nextCard];
	nextCard++;
	return c;

}

void Deck::error(std::string s)
{
	throw std::out_of_range(s);
}

Deck::~Deck()
{

}


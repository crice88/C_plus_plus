/*
 * AIPlayer.cpp
 *
 *  Created on: May 10, 2015
 *      Author: student
 */

#include "AIPlayer.h"
#include "Player.h"
#include "Deck.h"
#include <vector>
#include <algorithm>

AIPlayer::AIPlayer()
{
	// TODO Auto-generated constructor stub
}

const Card AIPlayer::playCard(const Card playerCard)
{
	std::sort(hand.begin(), hand.end());	// Sort hand by least to greatest rank card
	Card c = hand[0];	// Generic card object
	int cardIndex;	// Tells what vector element to erase
	bool end;	// Creates an outer looping break boolean

	if(playerCard.isJoker())	// Check who has the special joker card, play a random card
	{
		std::cout << "It is the computers turn" << std::endl;
		int cardInHand = hand.size();	// Randomize cardIndex by total number of cards in hand
		int cardIndex = rand() % cardInHand;
		Card c = hand[cardIndex];
		hand.erase(hand.begin() + cardIndex);
		return c;
	}
	else
	{
		for(unsigned int i = 0; (i < hand.size()) || (end == true); i++)	// Run through computers hand, if card rank is greater/equal than player card,
																			// set card equal to that card, set loop break boolean, break out of statement
		{
			if(playerCard < hand[i])
			{
				c = hand[i];
				end = true;
				cardIndex = i;
				break;
			}
			else if((playerCard == hand[i]) && (i == hand.size() - 1))
			{
				c = hand[i];
				end = true;
				cardIndex = i;
				break;
			}
			else
			{
				c = hand[i];
				cardIndex = i;
				end = false;
			}
		}
		hand.erase(hand.begin() + cardIndex);
		return c;
	}
}
AIPlayer::~AIPlayer() {
	// TODO Auto-generated destructor stub
}


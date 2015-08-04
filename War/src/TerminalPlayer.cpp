/*
 * TerminalPlayer.cpp
 *
 *  Created on: May 4, 2015
 *      Author: student
 */

#include "TerminalPlayer.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

TerminalPlayer::TerminalPlayer()
{
	// TODO Auto-generated constructor stub

}

const Card TerminalPlayer::playCard(const Card opponentCard)
{
	unsigned int cardIndex = 0;

	if(opponentCard.isJoker())	// Check who has the special joker card
	{
		std::cout << "It is the human players turn" << std::endl;
	}

	std::cout << "Cards in your hand are: " << std::endl;	// Displays each card in hand by numerical index

	for(unsigned int i = 0; i < hand.size(); i++)
	{
		std::cout << i << " -- " << hand[i] << std::endl;
	}

	std::cout << "What card would you like to play?? Please enter 0 - " << (hand.size() - 1) << std::endl;
	std::cin >> cardIndex;	// Plays a card by the index associated with it

	while(cardIndex > (hand.size() - 1))	// Checks for correct index, if not, repeat selection
	{
		std::cout << "Invalid card, please try again..." << std::endl;
		std::cin >> cardIndex;
	}

	Card c = hand[cardIndex];
	hand.erase(hand.begin() + cardIndex);	// Erases the card from the deck

	return c;
}

TerminalPlayer::~TerminalPlayer()
{
	// TODO Auto-generated destructor stub
}


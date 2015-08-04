//============================================================================
// Name        : ThreeCardWar.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <vector>

#include "Deck.h"
#include "Card.h"
#include "TerminalPlayer.h"
#include "Player.h"
#include "AIPlayer.h"

using namespace std;

int main()
{
	// Game loop
	Deck gameDeck;	// Instantiates both players and the deck
	TerminalPlayer player;
	AIPlayer compPlayer;
	bool compFirst = false;
	bool playerFirst = false;
	gameDeck.shuffle();	// Shuffle the deck
	int randJoker = (rand() % 100);	// Randomly generates a number 0-99, if less than 50, player goes first

	for(int i = 0; i < 3; i++)	// Draw three cards each
	{
		player.receiveCard(gameDeck.draw());
		compPlayer.receiveCard(gameDeck.draw());
	}

	while(gameDeck.isEmpty() != true)	// While the deck still has cards in it
	{
		if(randJoker < 50)	// Checks who is going first
		{
			playerFirst = true;
		}
		else
		{
			compFirst = true;
		}

		if (compFirst == true)	// If computer won the last round, go first
		{
			Card joker = Card::getJoker();
			Card computerCard = compPlayer.playCard(joker);
			std::cout << "The computer plays a " << computerCard << std::endl;
			Card playerCard = player.playCard(computerCard);
			std::cout << "You play a " << playerCard << std::endl;
			if(playerCard < computerCard)
			{
				std::cout << "Computer player wins the round :(" << std::endl;
				compPlayer.addScore(2);
				compFirst = true;
				playerFirst = false;
				player.receiveCard(gameDeck.draw());
				compPlayer.receiveCard(gameDeck.draw());
				compPlayer.cardsPlayed(playerCard, computerCard);
			}
			else if(computerCard < playerCard)
			{
				std::cout << "You win this round!!" << std::endl;
				player.addScore(2);
				playerFirst = true;
				compFirst = false;
				player.receiveCard(gameDeck.draw());
				compPlayer.receiveCard(gameDeck.draw());
				compPlayer.cardsPlayed(playerCard, computerCard);
			}
			else if(playerCard == computerCard)
			{
				std::cout << "Draw!!" << std::endl;
				player.receiveCard(gameDeck.draw());
				compPlayer.receiveCard(gameDeck.draw());
				compPlayer.cardsPlayed(playerCard, computerCard);
			}
		}
		else if (playerFirst == true)	// If the player won the last round
		{
			Card joker = Card::getJoker();
			Card playerCard = player.playCard(joker);
			std::cout << "You play a " << playerCard << std::endl;
			Card computerCard = compPlayer.playCard(playerCard);
			std::cout << "The computer plays a " << computerCard << std::endl;
			if(playerCard < computerCard)
			{
				std::cout << "Computer player wins the round :(" << std::endl;
				compPlayer.addScore(2);
				compFirst = true;
				playerFirst = false;
				player.receiveCard(gameDeck.draw());
				compPlayer.receiveCard(gameDeck.draw());
				compPlayer.cardsPlayed(playerCard, computerCard);
			}
			else if(computerCard < playerCard)
			{
				std::cout << "You win this round!!" << std::endl;
				player.addScore(2);
				playerFirst = true;
				compFirst = false;
				player.receiveCard(gameDeck.draw());
				compPlayer.receiveCard(gameDeck.draw());
				compPlayer.cardsPlayed(playerCard, computerCard);
			}
			else if(playerCard == computerCard)
			{
				std::cout << "Draw!!" << std::endl;
				player.receiveCard(gameDeck.draw());
				compPlayer.receiveCard(gameDeck.draw());
				compPlayer.cardsPlayed(playerCard, computerCard);
			}
		}
		std::cout << "The score is ";
		cout << "Computer Player:" << compPlayer.getScore();
		cout << " Human Player:" << player.getScore() << endl;

		while((gameDeck.isEmpty() == true) && ((player.hasCards() && compPlayer.hasCards()) == true))	// While the deck is empty but cards in hand are still available
		{
			if (playerFirst == true)
			{
				Card joker = Card::getJoker();
				Card playerCard = player.playCard(joker);
				std::cout << "You play a " << playerCard << std::endl;
				Card computerCard = compPlayer.playCard(playerCard);
				std::cout << "The computer plays a " << computerCard << std::endl;
				if(playerCard < computerCard)	// No card is drawn, if one was, game would error
				{
					std::cout << "Computer player wins the round :(" << std::endl;
					compPlayer.addScore(2);
					compFirst = true;
					playerFirst = false;
					compPlayer.cardsPlayed(playerCard, computerCard);
				}
				else if(computerCard < playerCard)
				{
					std::cout << "You win this round!!" << std::endl;
					player.addScore(2);
					playerFirst = true;
					compFirst = false;
					compPlayer.cardsPlayed(playerCard, computerCard);
				}
				else if(playerCard == computerCard)
				{
					std::cout << "Draw!!" << std::endl;
					compPlayer.cardsPlayed(playerCard, computerCard);
				}
			}
			else if (compFirst == true)
			{
				Card joker = Card::getJoker();
				Card computerCard = compPlayer.playCard(joker);
				std::cout << "The computer plays a " << computerCard << std::endl;
				Card playerCard = player.playCard(computerCard);
				std::cout << "You play a " << playerCard << std::endl;
				if(playerCard < computerCard)
				{
					std::cout << "Computer player wins the round :(" << std::endl;
					compPlayer.addScore(2);
					compFirst = true;
					playerFirst = false;
					compPlayer.cardsPlayed(playerCard, computerCard);
				}
				else if(computerCard < playerCard)
				{
					std::cout << "You win this round!!" << std::endl;
					player.addScore(2);
					playerFirst = true;
					compFirst = false;
					compPlayer.cardsPlayed(playerCard, computerCard);
				}
				else if(playerCard == computerCard)
				{
					std::cout << "Draw!!" << std::endl;
					compPlayer.cardsPlayed(playerCard, computerCard);
				}
			}
			std::cout << "The score is ";
			cout << "Computer Player:" << compPlayer.getScore();
			cout << " Human Player:" << player.getScore() << endl;
		}

		if((gameDeck.isEmpty() == true ) && ((player.hasCards() && compPlayer.hasCards()) == false))	// When the deck and hands are empty, game is over
		{
			cout << "Final Score is ";	// Displays final score
			cout << "Computer Player:" << compPlayer.getScore();
			cout << " Human Player:" << player.getScore() << endl;

			if(compPlayer.getScore() < player.getScore())	// Announce who won
			{
				cout << "YOU WIN!!! YAY!!!";
			}
			else
			{
				cout << "The computer has bested you, better luck next time...";
			}
		}
	}
	// End game loop

	return 0;
}

/*
 * AIPlayer.h
 *
 *  Created on: May 10, 2015
 *      Author: student
 */
#include "Player.h"
#include "Card.h"
#include "Deck.h"

#ifndef AIPLAYER_H_
#define AIPLAYER_H_

class AIPlayer : public Player
{
public:
	AIPlayer();

	const Card playCard(const Card opponentCard);
	virtual ~AIPlayer();
};

#endif /* AIPLAYER_H_ */

/*
 * TerminalPlayer.h
 *
 *  Created on: May 4, 2015
 *      Author: student
 */
#include "Player.h"
#include "Card.h"

#ifndef TERMINALPLAYER_H_
#define TERMINALPLAYER_H_

class TerminalPlayer : public Player {
public:
	TerminalPlayer();
	virtual ~TerminalPlayer();

	const Card playCard(const Card opponentCard);
};

#endif /* TERMINALPLAYER_H_ */

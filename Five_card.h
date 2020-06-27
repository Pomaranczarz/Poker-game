#pragma once

#include "Deck.h"

class Five_card
{
	private:
		//users balance (5000$ in the beginning)
		int balance = 5000;
		//current bet
		unsigned bet = 0;
		Deck* talia;
		//sets user's bet
		void setBet();
		//returns won cash
		int get_win();
	public:
		Five_card();
		//simulates one round
		void play();
};


#pragma once

#include "Card.h"
#include <vector>

class Deck
{
	private:
		std::vector<Card*> deck;
		//tab containing all possible figures
		int figures[13]{14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
		//tab conataining all possible suites
		int suites[4]{4, 3, 2, 1};

		//vector containing cards held by user
		std::vector<Card*> hand;

		//rolls card form deck
		Card* rollCard();

		//sorts hand by figure
		void sort_by_figure();

		//sorts hand by color
		void sort_by_color();

		//checks if hand is empty
		bool hand_is_empty();
		///Card sets ==================================================
		//seeks for highest card
		void highCard();
		//returns number of pairs
		int countPairs();
		//seeks for 3 same figure cards
		bool set_trips();
		//seeks for 5 same figure cards
		bool straight();
		//seeks for 5 same color cards
		bool flush();
		//seeks for straight and 1 pair combination
		bool full_boat();
		//seeks for 4 same figure cards
		bool four_of_a_kind();
		//seeks for straight and flush at the same time combination
		bool straight_flush();
		//seeks for straight flush with highest figures
		bool royal_flush();
		///============================================================
	public:
		//creates deck
		Deck();

		//shows deck
		void showDeck();

		//adds card to deck
		void add_to_deck(Card* card);

		//returns size of deck
		int getSize();

		//checks your card set
		int set_type();

		//rolls your cards
		void rollHand();

		//shows your cards
		void showHand();

		//changes cards in hand
		void change_cards();

		//changes full hand
		void change_hand();

		//clears current hand
		void clear_hand();

		~Deck() {}
};


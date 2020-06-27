#pragma once

#include <iostream>
#include <string>

class Card
{
	private:
		int suite;
		int figure;

		//shows card's suite
		std::string getSuite();

		//shows card's figure
		std::string getFigure();
	public:
		//creates card with given values
		Card(int color, int value) { this->suite = color; this->figure = value;  }

		//shows card
		void showCard();

		//returns suite's value
		int get_suite();

		//returns figure's value
		int get_figure();
		~Card() {}
};


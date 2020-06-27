#include "Card.h"

std::string Card::getSuite()
{
	if (this->suite == 4)
		return "Pik";
	else if (this->suite == 3)
		return "Kier";
	else if (this->suite == 2)
		return "Karo";
	else if (this->suite == 1)
		return "Trefl";
}

std::string Card::getFigure()
{
	switch (this->figure)
	{
	case 14:
		return "As";
	case 13:
		return "Krol";
	case 12:
		return "Dama";
	case 11:
		return "Walet";
	default:
		return std::to_string(this->figure);
	}
}

void Card::showCard()
{
	std::cout <<"|" << this->getFigure() << " " << this->getSuite() << "|" << std::endl;
}

int Card::get_suite()
{
	return this->suite;
}

int Card::get_figure()
{
	return this->figure;
}
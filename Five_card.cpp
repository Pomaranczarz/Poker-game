#include "Five_card.h"

Five_card::Five_card()
{
	this->talia = new Deck();
}

void Five_card::play()
{
	int temp;
	this->setBet();
	this->talia->rollHand();
	this->talia->showHand();
	this->talia->change_cards();
	this->talia->showHand();
	temp = this->get_win();
	std::cout << "You've won: " << temp << "$" << std::endl;
	this->balance += temp;
	this->talia->clear_hand();
}

void Five_card::setBet()
{
	int choice;
	std::cout << "Your balance: " << this->balance << "$" << std::endl;
	std::cout << "Set bet: " << std::endl;
	std::cout << "1. 100$\n2. 200$\n3. 500$\n4. 1000$" << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		this->bet = 100;
		this->balance -= 100;
		break;
	case 2:
		this->bet = 200;
		this->balance -= 200;
		break;
	case 3:
		this->bet = 500;
		this->balance -= 500;
		break;
	case 4:
		this->bet = 1000;
		this->balance -= 1000;
		break;
	}
}

int Five_card::get_win()
{
	switch (this->talia->set_type())
	{
	case 9:
		return this->bet * 32;
	case 8:
		return this->bet * 16;
	case 7:
		return this->bet * 8;
	case 6:
		return this->bet * 6;
	case 5:
		return this->bet * 5;
	case 4:
		return this->bet * 4;
	case 3:
		return this->bet * 3;
	case 2:
		return this->bet * 2;
	case 1:
		return this->bet;
	}
}
#include "Deck.h"

Deck::Deck()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++)
		{
			this->add_to_deck(new Card(this->suites[i], this->figures[j]));
		}
}

void Deck::showDeck()
{
	for (size_t i = 0; i < this->deck.size(); i++)
	{
		std::cout << i + 1 << ". ";
		this->deck[i]->showCard();
	}
}

void Deck::add_to_deck(Card* card)
{
	this->deck.push_back(card);
}

Card* Deck::rollCard()
{
	int it = rand() % this->deck.size();
	Card* temp = this->deck[it];
	this->deck.erase(this->deck.begin() + it);
	return temp;
}

int Deck::getSize()
{
	return this->deck.size();
}

void Deck::showHand()
{
	if (!this->hand_is_empty())
	{
		this->sort_by_figure();
		std::cout << "YOUR DECK: " << std::endl;
		for (size_t i = 0; i < this->hand.size(); i++)
		{
			std::cout << i + 1 << ". ";
			this->hand[i]->showCard();
		}
	}
	else
		std::cout << "Hand is empty!" << std::endl;
}

void Deck::rollHand()
{
	for (size_t i = 0; i < 5; i++)
		this->hand.push_back(this->rollCard());
}

void Deck::highCard()
{
	Card* highCard = this->hand[0];
	for (size_t i = 1; i < this->hand.size(); i++)
	{
		if (highCard->get_figure() < this->hand[i]->get_figure())
			highCard = this->hand[i];
	}
	std::cout << "High card: " << std::endl;
	highCard->showCard();
}

int Deck::countPairs()
{
	int pairs = 0;
	if (!this->hand_is_empty())
	{

		for (size_t i = 0; i < this->hand.size(); i++)
			for (size_t j = i + 1; j < this->hand.size(); j++)
			{
				if (this->hand[i]->get_figure() == this->hand[j]->get_figure())
				{
					pairs++;
					break;
				}
			}

		return pairs;
	}
	else
	{
		std::cout << "Hand is empty!" << std::endl;
		return 0;
	}
}

bool Deck::set_trips()
{
	if (!this->hand_is_empty())
	{
		int cards = 1;
		for (size_t i = 0; i < this->hand.size() - 1; i++)
		{
			for (size_t j = i + 1; j < this->hand.size(); j++)
			{
				if (this->hand[i]->get_figure() == this->hand[j]->get_figure())
					cards++;
				if (cards == 3)
					return true;
			}
			cards = 1;
		}
		return false;
	}
	else
	{
	std::cout << "Hand is empty!" << std::endl;
	return false;
	}
}

bool Deck::straight()
{
	if (!this->hand_is_empty())
	{
		this->sort_by_figure();
		for (size_t i = 0; i < this->hand.size() - 1; i++)
			if (this->hand[i]->get_figure() + 1 ==  this->hand[i + 1]->get_figure())
				continue;
			else
				return false;
		return true;
	}
	else
	{
		std::cout << "Hand is empty!" << std::endl;
		return false;
	}
}

void Deck::sort_by_figure()
{
	if (!this->hand_is_empty())
	{
		for (size_t i = 0; i < this->hand.size() - 1; i++)
		{
			for (size_t j = 0; j < this->hand.size() - i - 1; j++)
			{
				if (this->hand[j]->get_figure() > this->hand[j + 1]->get_figure())
					std::swap(this->hand[j], this->hand[j + 1]);
			}
		}
	}
	else
		return;
}

void Deck::sort_by_color()
{
	if (!this->hand_is_empty())
	{
		for (size_t i = 0; i < this->hand.size() - 1; i++)
		{
			for (size_t j = 0; j < this->hand.size() - i - 1; j++)
			{
				if (this->hand[j]->get_suite() > this->hand[j + 1]->get_suite())
					std::swap(this->hand[j], this->hand[j + 1]);
			}
		}
	}
	else
		return;
}

bool Deck::flush()
{
	if (!this->hand_is_empty())
	{
		this->sort_by_color();
		for (size_t i = 0; i < this->hand.size(); i++)
		{
			if (this->hand[i]->get_suite() != this->hand[i + 1]->get_suite())
				return false;
		}
		return true;
	}
	else
		return false;
}

bool Deck::hand_is_empty()
{
	if (this->hand.size() == 0)
		return true;
	else
		return false;
}

bool Deck::full_boat()
{
	this->sort_by_figure();
	if (this->hand[0]->get_figure() == this->hand[1]->get_figure() == this->hand[2]->get_figure())
	{
		if (this->hand[3]->get_figure() == this->hand[4]->get_figure())
			return true;
		else
			return false;
	}
	else if (this->hand[0]->get_figure() == this->hand[1]->get_figure())
	{
		if (this->hand[2]->get_figure() == this->hand[3]->get_figure() == this->hand[4]->get_figure())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Deck::four_of_a_kind()
{
	if (!this->hand_is_empty())
	{
		int cards = 1;
		for (size_t i = 0; i < this->hand.size() - 1; i++)
		{
			for (size_t j = i + 1; j < this->hand.size(); j++)
			{
				if (this->hand[i]->get_figure() == this->hand[j]->get_figure())
					cards++;
				if (cards == 4)
					return true;
			}
			cards = 1;
		}
		return false;
	}
	else
		return false;
}

bool Deck::straight_flush()
{
	if (this->straight() && this->flush())
		return true;
	else
		return false;
}

bool Deck::royal_flush()
{
	this->sort_by_figure();
	if (this->hand[0]->get_figure() == 10)
	{
		if (this->straight() && this->flush())
			return true;
		else
			return false;
	}
	else
		return false;
}

int Deck::set_type()
{
	std::cout << std::string(60, '=') << std::endl;
	if (this->royal_flush())
	{
		std::cout << "Royal flush!" << std::endl;
		return 9;
	}
	else if (this->straight_flush())
	{
		std::cout << "Straight flush!" << std::endl;
		return 8;
	}
	else if (this->four_of_a_kind())
	{
		std::cout << "Four of a kind!" << std::endl;
		return 7;
	}
	else if (this->full_boat())
	{
		std::cout << "Full boat!" << std::endl;
		return 6;
	}
	else if (this->flush())
	{
		std::cout << "Flush!" << std::endl;
		return 5;
	}
	else if (this->straight())
	{
		std::cout << "Straight!" << std::endl;
		return 4;
	}
	else if (this->set_trips())
	{
		std::cout << "Set-trips!" << std::endl;
		return 3;
	}
	else if (this->countPairs() == 2)
	{
		std::cout << "Two pairs" << std::endl;
		return 2;
	}
	else if (this->countPairs() == 1)
	{
		std::cout << "Pair" << std::endl;
		return 1;
	}
	else
	{
		this->highCard();
		return 0;
	}
	std::cout << std::string(60, '=') << std::endl;
}

void Deck::change_cards()
{
	int num;
	std::cout << "How many cards do you want to change?" << std::endl;
	std::cin >> num;
	while (num < 0 || num > 4)
	{
		std::cout << "Please enter valid number!" << std::endl;
		std::cin >> num;
	}
	int index;
	Card* temp = nullptr;
	std::vector<Card*>::iterator it;
	switch (num)
	{
	case 0:
		return;
	case 1:
		it = this->deck.begin();
		std::cout << "Which card do you want to change?" << std::endl;
		std::cin >> index;
		while (index < 0 || index > 5)
		{
			std::cout << "Please enter valid number!" << std::endl;
			std::cin >> index;
		}
		temp = this->hand[index - 1];
		it = this->deck.insert(it + this->getSize(), temp);
		this->hand.erase(this->hand.begin() + index - 1);
		this->hand.push_back(this->rollCard());
		break;
	case 2:
		for (int i = 0; i < 2; i++)
		{
			it = this->deck.begin();
			std::cout << "Which card do you want to change?" << std::endl;
			std::cin >> index;
			while (index < 0 || index > 5)
			{
				std::cout << "Please enter valid number!" << std::endl;
				std::cin >> index;
			}
			temp = this->hand[index - 1];
			it = this->deck.insert(it + this->getSize(), temp);
			this->hand.erase(this->hand.begin() + index - 1 - i);
			this->hand.push_back(this->rollCard());
		}
		break;
	case 3:
		for (int i = 0; i < 3; i++)
		{
			it = this->deck.begin();
			std::cout << "Which card do you want to change?" << std::endl;
			std::cin >> index;
			while (index < 0 || index > 5)
			{
				std::cout << "Please enter valid number!" << std::endl;
				std::cin >> index;
			}
			temp = this->hand[index - 1];
			it = this->deck.insert(it + this->getSize(), temp);
			this->hand.erase(this->hand.begin() + index - 1 - i);
			this->hand.push_back(this->rollCard());
		}
		break;
	case 4:
		for (int i = 0; i < 4; i++)
		{
			it = this->deck.begin();
			std::cout << "Which card do you want to change?" << std::endl;
			std::cin >> index;
			while (index < 0 || index > 5)
			{
				std::cout << "Please enter valid number!" << std::endl;
				std::cin >> index;
			}
			temp = this->hand[index - 1];
			it = this->deck.insert(it + this->getSize(), temp);
			this->hand.erase(this->hand.begin() + index - 1 - i);
			this->hand.push_back(this->rollCard());
		}
		break;
	}

}

void Deck::change_hand()
{
	this->clear_hand();
	this->rollHand();
}

void Deck::clear_hand()
{
	std::vector<Card*>::iterator it = this->deck.begin();
	it = this->deck.insert(it + this->deck.size(), this->hand.begin(), this->hand.end());
	this->hand.clear();
}
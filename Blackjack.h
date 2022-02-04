#pragma once

enum Values
{
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
	SIX = 6,
	SEVEN = 7,
	EIGHT = 8,
	NINE = 9,
	TEN = 10,
	JACK = 10,
	QUEEN = 10,
	KING = 10,
	ACE = 11,
	NUM_OF_VALUES = 13,
};

enum Suits
{
	DIAMONDS = 0,
	HEARTS = 1,
	CLUBS = 2,
	SPADES = 3,
	NUM_OF_SUITS = 4,
};

struct Card
{
	Values Value;
	Suits Suit;
};

void swapCard(Card& a, Card& b)
{
	Card tmp = a;
	a = b;
	b = tmp;
}

void shuffleDeck(std::array<Card, 52>& deck)
{
	for (int index = 0; index < deck.size(); ++index)
	{
		int randomIndex = rand() % deck.size();
		swapCard(deck.at(index), deck.at(randomIndex));
	}
}

int getCardValue(const std::array<Card, 52>& deck, int index)
{
	Card card = deck.at(index);
	int cardValue = static_cast<int>(card.Value);
	return cardValue;
}

void initDeck(std::array<Card, 52>& deck)
{
	int card = 0;
	for (int cardValue = 0; cardValue < Values::NUM_OF_VALUES; ++cardValue)
	{
		for (int cardSuit = 0; cardSuit < Suits::NUM_OF_SUITS; ++cardSuit)
		{
			deck.at(card).Value = static_cast<Values>(cardValue);
			deck.at(card).Suit = static_cast<Suits>(cardSuit);
			card++;
		}
	}
}

bool Total(const int playerCount, const int dealerCount) 
{
	if (dealerCount > 21) return true;

	if (dealerCount < 21) 
	{
		if (playerCount > dealerCount) return true;

		else if (playerCount == dealerCount) 
		{
			std::cout << "Draw!" << std::endl;
			return 0;
		}

		else return false;
	}
}

int Blackjack(std::array<Card, 52>& deck)
{
	int dealerCount = 0;
	int playerCount = 0;
	int index = 0;
	int userChoice = 0;

	std::cout << "Shuffling the deck..." << std::endl << std::endl;
	shuffleDeck(deck);

	dealerCount = getCardValue(deck, index++);
	std::cout << "Dealer got his card" << std::endl << std::endl;

	playerCount = getCardValue(deck, index++) + getCardValue(deck,index++);
	std::cout << "You got your cards! Your total is: " << playerCount << std::endl << std::endl;

	std::cout << "Your turn" << std::endl << std::endl;
	while (true) 
	{
		std::cout << "Would like to hit(0) or stand(1) ? ";
		std::cin >> userChoice;
		switch (userChoice)
		{
		default:
			std::cout << "Wrong number! Please try again" << std::endl;
			break;
		case 0:
			playerCount += getCardValue(deck, index++);
			break;
		case 1:
			break;
		}
		break;
	}

	std::cout << "Your total is: " << playerCount << std::endl;
	if (playerCount > 21)
	{
		std::cout << "Your total is more than 21! You lost" << std::endl;
		return 0;
	}

	while (dealerCount < 17) 
	{
		dealerCount = dealerCount + getCardValue(deck, index++);
	}
	std::cout << "Dealer's total: " << dealerCount << std::endl;

	if (Total(playerCount, dealerCount))
	{
		std::cout << "Congrats! You won" << std::endl << std::endl;
		return 0;
	}
	else 
	{
		std::cout << "You lost!" << std::endl << std::endl;
		return 0;
	}
}

int startLoop (std::array<Card, 52>& deck)
{
	std::cout << "Blackjack v0.1" << std::endl << std::endl;
	int userChoice = 0;
	while (true)
	{
		
		std::cout << "To select press the corresponding button: " << std::endl;
		std::cout << "1. Start Game" << std::endl;
		std::cout << "2. Exit" << std::endl;
		std::cout << "Input: ";
		std::cin >> userChoice;
		std::cout << std::endl;
		switch (userChoice)
		{
		default:
			std::cout << "Wrong number! Please try again" << std::endl;
			break;
		case 1:
			Blackjack(deck);
			break;
		case 2:
			std::cout << "Are you sure you want to exit the execution of the program ?" << std::endl;
			std::cout << "Yes(0) / No(1) : ";
			std::cin >> userChoice;
			std::cout << std::endl;
			if (!userChoice)
			{
				std::cout << "Terminating the programm....";
				return 0;
			}
			else
			{
				std::cout << "Welcome back!" << std::endl;
				break;
			}
		}
	}
}

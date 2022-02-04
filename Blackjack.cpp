#include <iostream>
#include <array>
#include "Blackjack.h"


int main()
{
	srand(time(0));
	rand();

	std::array<Card, 52> deck;
	initDeck(deck);

	startLoop(deck);
}


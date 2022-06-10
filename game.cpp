#include <iostream>
#include "io.h"

// main game code, takes in mt, gets guesses, determines win or loss state, reports back to user
void playGame(int randomNumber)
{
	std::cout << "*********************************************************************************\n";
	std::cout << "Let's play Hi-Lo! I'm thinking of a number. You have 7 tries to guess what it is.\n\n";

	bool winner{ getGuesses(randomNumber) };

	if (winner == true)
		std::cout << "Correct! You win!\n\n";
	else
	{
		std::cout << "...........................................\n";
		std::cout << "Sorry, you lose. The correct number was " << randomNumber << ".\n";
		std::cout << "...........................................\n\n";
	}
}
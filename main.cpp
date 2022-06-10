#include <iostream>
#include <random>
#include "io.h"
#include "mt.h"

int main()
{
	while (true)
	{
		std::cout << "*********************************************************************************\n";
		std::cout << "Let's play Hi-Lo! I'm thinking of a number. You have 7 tries to guess what it is.\n\n";

		// call a mersenne twister and store it as an integer
		int randomNumber{ (randomRoll(mt)) };

		int getGuess{ randomNumber };

		// user gets 7 tries to guess the number
		for (int guesses{ 1 }; (guesses <= 7); ++guesses)
		{
			std::cout << "Guess #" << guesses << ": ";
			int userNumber{};
			std::cin >> userNumber;

			// call function to cleanup input
			inputCleanup();

			{
				if (userNumber == randomNumber)
				{
					std::cout << "Correct! You win!\n\n";
					break;
				}
				else if (userNumber > randomNumber)
				{
					std::cout << "Your guess is too high.\n\n";
				}
				else if (userNumber < randomNumber)
				{
					std::cout << "Your guess is too low.\n\n";
				}
			}
			if ((guesses == 7) && (userNumber != randomNumber))
			{
				std::cout << "...........................................\n";
				std::cout << "Sorry, you lose. The correct number was " << randomNumber << ".\n";
				std::cout << "...........................................\n\n";
			}
		}
		bool playAgain{ askPlayAgain() };
		if (playAgain)
			continue;
		else
			return 0;
	}
	

}
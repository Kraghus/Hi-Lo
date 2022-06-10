#include <iostream>
#include "io.h"

// get up to 7 guesses from the user and give feedback as to the direction of the random number
bool getGuesses(int randomNumber)
{
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
				return true;
			}
			else if (userNumber > randomNumber)
			{
				std::cout << "Your guess is too high.\n\n";
				continue;
			}
			else if (userNumber < randomNumber)
			{
				std::cout << "Your guess is too low.\n\n";
				continue;
			}
		}
		if ((guesses == 7) && (userNumber != randomNumber))
		{
			return false;
		}
	}
}

// ask the user if they would like to play again
bool askPlayAgain()
{
	while (true)
	{
		std::cout << "Would you like to play again? Enter 'Y' for YES or 'N' for NO.\n";
		char yesOrNo{};
		std::cin >> yesOrNo;

		// call function to cleanup input
		inputCleanup();

		if ((yesOrNo == 'y') || (yesOrNo == 'Y'))
		{
			return true;
		}
		else if ((yesOrNo == 'n') || (yesOrNo == 'N'))
		{
			std::cout << "****************************\n";
			std::cout << "Thank you for playing Hi-Lo!\n";
			std::cout << "****************************";
			return false;
		}
		else
		{
			std::cout << "Invalid input detected. Please try again!\n";
			continue;
		}
	}
}
#include <iostream>
#include "io.h"

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
			std::cout << "Thank you for playing Hi-Lo!\n";
			return false;
		}
		else
		{
			std::cout << "Invalid input detected. Please try again!\n";
			continue;
		}
	}
}
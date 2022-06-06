#include <iostream>
#include <random>

// mersenne twister
static std::random_device rd; // call numbers from OS
static std::seed_seq seedSequence{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() }; // seed with OS numbers
static std::mt19937 mt{ seedSequence }; // assign random number with seed
std::uniform_int_distribution<> randomRoll{ 1, 100 }; // using integers 1 through 100

int main()
{
	while (true)
	{
		std::cout << "*********************************************************************************\n";
		std::cout << "Let's play Hi-Lo! I'm thinking of a number. You have 7 tries to guess what it is.\n\n";

		// call a mersenne twister and store it as an integer
		int randomNumber{ (randomRoll(mt)) };

		// user gets 7 tries to guess the number
		for (int guesses{ 1 }; (guesses <= 7); ++guesses)
		{
			std::cout << "Guess #" << guesses << ": ";
			int userNumber{};
			std::cin >> userNumber;
			{

				if (userNumber == randomNumber)
				{
					std::cout << "Correct! You win!\n\n";
					return 0;
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
		}
		std::cout << "...........................................\n";
		std::cout << "Sorry, you lose. The correct number was " << randomNumber << ".\n";
		std::cout << "...........................................\n\n";

		while (true)
		{
			std::cout << "Would you like to play again? Enter 'Y' for YES or 'N' for NO.\n";
			char yesOrNo{};
			std::cin >> yesOrNo;

		
			if ((yesOrNo == 'y') || (yesOrNo == 'Y'))
			{
				break;
			}
			else if ((yesOrNo == 'n') || (yesOrNo == 'N'))
			{
				std::cout << "Thank you for playing Hi-Lo!\n";
				return 0;
			}
			else
			{
				std::cout << "Invalid input detected. Please try again!\n";
				continue;
			}
		}


	}
}
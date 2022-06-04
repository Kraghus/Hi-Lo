#include <iostream>
#include <random>

int main()
{
	// call random numbers from the OS and store them in rd
	std::random_device rd;
	// get 8 integers of random numbers from std::random_device for our seed
	std::seed_seq seedSequence{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() }; 
	// initialize our Mersenne Twister with the std::seed_seq
	std::mt19937 mt{ seedSequence }; // initialize our Mersenne Twister with the std::seed_seq

	// Create a reusable random number generator that generates uniform numbers between 1 and 6
	std::uniform_int_distribution<> randomRoll{ 1, 100 };

	std::cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.\n";

	
	int randomNumber{ (randomRoll(mt)) };
	for (int guesses{ 1 }; (guesses <= 7); ++guesses)
	{
		std::cout << "Guess #" << guesses << ": ";
		int userNumber{};
		std::cin >> userNumber;

		if (userNumber == randomNumber)
		{
			std::cout << "Correct! You win!\n";
			break;
		}
		else if (userNumber > randomNumber)
		{
			std::cout << "Your guess is too high.\n";
		}
		else
		{
			std::cout << "Your guess is too low.\n";
		}
	}
	std::cout << "Sorry, you lose. The correct number was " << randomNumber << ".\n";
	return 0;
}
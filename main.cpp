#include <iostream>
#include <random>
#include "io.h"
#include "mt.h"

int main()
{
	while (true)
	{
		// call a mersenne twister and store it as an integer
		int randomNumber{ (randomRoll(mt)) };

		// send the mersenne twister to the game loop and start the game
		playGame(randomNumber);

		// ask the user if they would like to play again
		bool playAgain{ askPlayAgain() };
		if (playAgain)
			continue;
		else
			return 0;
	}
}
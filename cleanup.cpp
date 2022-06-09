#include <iostream>
#include "cleanup.h"

// perform cleanup function for input
void inputCleanup()
{
	// clears any extraneous input
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// tests and fixes failed extractions and overflow
	if (!std::cin)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}
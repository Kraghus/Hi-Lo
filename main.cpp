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
	std::uniform_int_distribution<> randomNumber{ 1, 100 };

	return 0;
}
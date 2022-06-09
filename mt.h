#include <random>

#ifndef MT_H
#define MT_H

// mersenne twister
static std::random_device rd; // call numbers from OS
static std::seed_seq seedSequence{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() }; // seed with OS numbers
static std::mt19937 mt{ seedSequence }; // assign random number with seed
std::uniform_int_distribution<> randomRoll{ 1, 100 }; // using integers 1 through 100

#endif MT_H

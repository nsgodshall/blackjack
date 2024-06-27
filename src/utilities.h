#ifndef UTILITIES_INCLUDED
#define UTILITIES_INCLUDED

#include <vector>

#include "card.h"

const int MIN_BET = 10;
const int MAX_BET = 200;
const int DEFAULT_PURSE = 1000;

int getCardVal(const card &c);

int getHandVal(const std::vector<card> &hand);

#endif // UTILITIES_INCLUDED

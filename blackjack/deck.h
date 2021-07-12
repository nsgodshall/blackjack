#ifndef DECK_INCLUDED
#define DECK_INCLUDED

#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

#include "card.h"

class deck {
	public:
		deck();
		deck(int shoeSize);
		bool shuffleDeck();
		bool drawCard(card &c);
		void dump(); 
	private: 
		//std::vector<std::pair<char, char>> m_cards;
		std::vector<card> m_cards;
		int m_nCards;
};


#endif //DECK_INCLUDED

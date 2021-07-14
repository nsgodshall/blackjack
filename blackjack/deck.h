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

		//accessors 
		int size() const { return m_nCards; }

		//mutators 
		bool shuffleDeck();
		bool drawCard(card &c);
		void dump(); 
	private: 
		std::vector<card> m_cards;
		int m_nCards;
};


#endif //DECK_INCLUDED

#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <string>
#include <vector>

#include "deck.h"
#include "player.h"
#include "utilities.h"

//int MIN_DECK_SIZE = 30;
//int DEFAULT_SHOE_SIZE = 6;

class game {
	public:
		game(int numPlayers);
		game(int numPlaters, int shoeSize);
		void play();
	private:
		void deal();


		std::vector<player*> m_allPlayers;
		deck m_gameDeck;
		int m_shoeSize;


};

#endif //GAME_INCLUDED
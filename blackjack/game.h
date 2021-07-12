#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <string>
#include <vector>

#include "deck.h"

class game {
	public:
		game(int numPlayers);
		void play();
	private:
		std::string 
		//std::vector<player*> m_allPlayers;
		//deck m_gameDeck;


};

#endif //GAME_INCLUDED
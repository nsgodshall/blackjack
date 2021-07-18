#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <string>
#include <vector>

#include "deck.h"
#include "player.h"
#include "utilities.h"

const int MIN_DECK_SIZE = 30;
const int DEFAULT_SHOE_SIZE = 6;
const int MIN_BET = 10;
const int MAX_BET = 200;

class game {
	public:
		game(int numPlayers);
		game(int numPlaters, int shoeSize);
		void playGame();
	private:
		void deal();
		void setWagers();
		void playRound();

		// TODO: Replace this function, this is a placeholder
		void determineWinners();

		std::vector<player*> m_allPlayers;
		dealer m_dealer;
		deck m_gameDeck;
		int m_shoeSize;


};

#endif //GAME_INCLUDED
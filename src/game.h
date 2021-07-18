#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <map>
#include <string>
#include <vector>

#include "deck.h"
#include "player.h"
#include "utilities.h"

const int MIN_DECK_SIZE = 30;
const int DEFAULT_SHOE_SIZE = 6;


class game {
	public:
		game(int nRandom, int nStandard, int nHuman);
		game(int numPlaters, int shoeSize);
		void play();
	private:
		void deal();
		void setWagers();
		void manageRound();
		void manageRoundVerbose();
		void playRound();
		void playRoundVerbose();

		// TODO: Replace this function, this is a placeholder
		void settleUp();
		std::vector<player*> m_allPlayers;
		std::map<player*, int> m_wagers;
		dealer m_dealer;
		deck m_gameDeck;
		int m_shoeSize;


};

#endif //GAME_INCLUDED
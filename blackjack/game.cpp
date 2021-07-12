#include "game.h"

game::game(int numPlayers) {
	//initialize all of the players
	std::string namePlaceHolder;

	for (int i = 0; i < numPlayers; i++) {
		std::cout << "Enter the name of player " << i + 1  << ": ";
		std::cin >> namePlaceHolder;
		m_allPlayers.push_back(new randomPlayer(namePlaceHolder));
	}
	//shuffle the deck
	m_gameDeck.shuffleDeck();
}

void game::play() {
	for (int i = 0; i < m_allPlayers.size(); i++) {
		for (int j = 0; j < 2; j++) {
			card c;
			if (!m_gameDeck.drawCard(c)) {
				//shuffle then draw a new card
			}
			//m_allPlayers[i]->addCard(m_gameDeck.drawCard());
			m_allPlayers[i]->addCard(c);
			std::cout << c.val << std::endl;
		}
		std::cerr << getHandVal(m_allPlayers[i]->getHand()) << std::endl;
		std::cerr << "=====" << std::endl;
	}
	
	
}
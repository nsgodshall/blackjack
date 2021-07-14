#include "game.h"

game::game(int numPlayers) 
	: m_gameDeck(6), m_shoeSize(6)
{
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

game::game(int numPlayers, int shoeSize)
	: m_gameDeck(shoeSize), m_shoeSize(shoeSize)
{
	//initialize all of the players
	std::string namePlaceHolder;

	for (int i = 0; i < numPlayers; i++) {
		std::cout << "Enter the name of player " << i + 1 << ": ";
		std::cin >> namePlaceHolder;
		m_allPlayers.push_back(new randomPlayer(namePlaceHolder));
	}
	//shuffle the deck
	m_gameDeck.shuffleDeck();
}

void game::play() {
	// TODO: Replace 30 with MIN_DECK_SIZE	
	if (m_gameDeck.size() < 30) {
		m_gameDeck = deck(m_shoeSize);
	}
	deal();
	card c;
	for (int i = 0; i < m_allPlayers.size(); i++) {
		std::cerr << m_allPlayers[i]->getName() << "'s turn: " << std::endl;
		std::cerr << "HAND: ";
		m_allPlayers[i]->dumpHand();
		std::cout << "Val is: " << getHandVal(m_allPlayers[i]->getHand()) << std::endl;
		while (m_allPlayers[i]->makeMove() == 'h') {
			m_gameDeck.drawCard(c);
			m_allPlayers[i]->addCard(c);
			m_allPlayers[i]->dumpHand();
			std::cout << "Val is: " << getHandVal(m_allPlayers[i]->getHand()) << std::endl;

			if (getHandVal(m_allPlayers[i]->getHand()) == -1) {
				std::cout << "BUST!" << std::endl;
				break;
			}
		}
	}
	
}

void game::deal() {
	for (int i = 0; i < m_allPlayers.size(); i++) {
		m_allPlayers[i]->clearHand();
		for (int j = 0; j < 2; j++) {
			card c;
			m_gameDeck.drawCard(c);
			m_allPlayers[i]->addCard(c);
		}
	}
}
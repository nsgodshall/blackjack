#include "game.h"

game::game(int numPlayers) 
	: m_gameDeck(DEFAULT_SHOE_SIZE), m_shoeSize(DEFAULT_SHOE_SIZE)
{
	//initialize all of the players
	std::string namePlaceHolder;

	for (int i = 0; i < numPlayers; i++) {
		std::cout << "Enter the name of player " << i + 1  << ": ";
		std::cin >> namePlaceHolder;

		if (i == 0) {
			m_allPlayers.push_back(new humanPlayer(namePlaceHolder));
		}
		else if (i == 1)
			m_allPlayers.push_back(new standardPlayer(namePlaceHolder));
		else
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
		m_wagers[m_allPlayers.back()] = 0;
	}
	//shuffle the deck
	m_gameDeck.shuffleDeck();
}

void game::playGame() {
	// TODO: Replace 30 with MIN_DECK_SIZE	
	if (m_gameDeck.size() < MIN_DECK_SIZE) {
		m_gameDeck = deck(m_shoeSize);
	}
	std::cout << std::endl << "=== MAKE  BETS ===";
	setWagers();
	std::cout << std::endl << "====== DEAL ======" << std::endl;
	deal();
	std::cout << "DEALER: " << "XX, " << m_dealer.getHand().back().suit << m_dealer.getHand().back().val << std::endl;

	for (player* p : m_allPlayers) {
		std::cout << p->getName() << ": ";
		p->dumpHand();
		std::cout << std::endl;
	}
	std::cout << std:: endl << "=== BEGIN PLAY ===" << std::endl;
	playRound();
	settleUp();
}

void game::deal() {
	card c;
	m_dealer.clearHand();
	for (int i = 0; i < 2; i++) {
		m_gameDeck.drawCard(c);
		m_dealer.addCard(c);
	}

	for (player* p : m_allPlayers) {
		p->clearHand();
		for (int j = 0; j < 2; j++) {
			m_gameDeck.drawCard(c);
			p->addCard(c);
		}
	}
}

void game::setWagers(){
	for (player* p : m_allPlayers){
		int wager = p->makeWager();
		std::cerr << p->getName() << ": $" << wager << std::endl; 
		m_wagers[p] = wager;
	}
}

void game::playRound() {
	card c;
	for (player* p : m_allPlayers) {
		std::cout << std::endl << p->getName() << "'s turn: " << std::endl;
		std::cout << "HAND: ";
		p->dumpHand();
		std::cerr << " (Val is: " << getHandVal(p->getHand()) << ")";
		std::cout << std::endl; 
		
		while (p->makeMove(m_dealer.getHand().back()) == 'h') {
			std::cout << "HIT!" << std::endl;
			std::cout << "HAND: ";
			m_gameDeck.drawCard(c);
			p->addCard(c);
			p->dumpHand();
			std::cerr << " (Val is: " << getHandVal(p->getHand()) << " )";
			std::cout << std::endl;
			if (getHandVal(p->getHand()) == -1) {
				std::cout << "BUST!" << std::endl;
				break;
			}
		}
		if (getHandVal(p->getHand()) != -1) {
			std::cout << "STAY!" << std::endl;
		}
	}

	std::cout << "DEALER: ";
	m_dealer.dumpHand();
	std::cout << std::endl;

	while (m_dealer.makeMove() == 'h') {
		m_gameDeck.drawCard(c);
		m_dealer.addCard(c);
		m_dealer.dumpHand();
		std::cout << std::endl;
	}
}

void game::settleUp() {
	std::vector<player*> winners;
	std::vector<player*> losers;
	std::vector<player*> ties;
	int dealerVal = getHandVal(m_dealer.getHand());
	
	//dealer busted 
	if (dealerVal == -1) {
		for (player* p : m_allPlayers) {
			if (getHandVal(p->getHand()) != -1)
				winners.push_back(p);
			else
				losers.push_back(p);
		}
	}
	else {
		for (player* p : m_allPlayers) {
			int pHand = getHandVal(p->getHand());
			if (pHand == -1)
				losers.push_back(p);
			else if (pHand > dealerVal)
				winners.push_back(p);
			else if (pHand < dealerVal)
				losers.push_back(p);
			else if (pHand == dealerVal)
				ties.push_back(p);
		}
	}
	std::cerr << "WINNERS: ";
	for (player* w : winners) {
		w->addMoney(2*m_wagers[w]);
		std::cerr << w->getName() << ": " << w->getPurse() - m_wagers[w] << " ----> " << w->getPurse() << std::endl;
	}
	std::cerr << "LOSERS: ";
	for (player* l : losers) {
		std::cerr << l->getName() << ": " << l->getPurse() + m_wagers[l] << " ----> " << l->getPurse() << std::endl;
	}
	std::cerr << std::endl;
	std::cerr << "TIES: ";
	for (player* t : ties) {
		t->addMoney(m_wagers[t]);
		std::cerr << t->getName() << ": " << t->getPurse() << " ----> " << t->getPurse() << std::endl;
	}
	std::cerr << std::endl;
}
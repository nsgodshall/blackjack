#include <ctime>
#include <iostream>
#include <random>

#include "player.h"


player::player(std::string name)
	: m_name(name), m_purse(100)
{}

player::player(std::string name, int purse)
	: m_name(name), m_purse(purse)
{}

bool player::addCard(card c) {
	m_hand.push_back(c);
	return true;
}

player::~player()
{}

void player::dumpHand() const{
	for (int i = 0; i < m_hand.size() - 1; i++) {
		std::cerr << m_hand[i].suit << m_hand[i].val << ", ";
	}
	std::cout << m_hand.back().suit << m_hand.back().val;
	std::cout << std::endl;
}

//RANDOM PLAYER IMPLEMENTATIONS
randomPlayer::randomPlayer(std::string name)
	: player(name)
{}

randomPlayer::randomPlayer(std::string name, int purse)
	: player(name, purse)
{}

char randomPlayer::makeMove() const {
	if (std::rand() % 2 > 0.5)
		return 'h';
	else
		return 's';
}
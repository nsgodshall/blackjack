#include <ctime>
#include <iostream>
#include <random>
#include <set>

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
}

int player::makeWager() {
	int wager = MIN_BET;
	m_purse -= wager;
	return wager;
}

//DEALER IMPLEMENTATIONS

dealer::dealer()
	: player("dealer")
{}

char dealer::makeMove() const {
	if (getHandVal(getHand()) >= 17 || getHandVal(getHand()) == -1) 
		return 's';
	return 'h';
}

//HUMAN PLAYER IMPLEMENTATIONS
humanPlayer::humanPlayer(std::string name)
	: player(name)
{}

humanPlayer::humanPlayer(std::string name, int purse)
	: player(name, purse)
{}

char humanPlayer::makeMove(card& d) const {
	char i = 'x';
	std::cout << "WHAT";
	while (tolower(i) != 's' && tolower(i) != 'h') {
		std::cout << std::endl << "CHOOSE MOVE: ";
		std::cin >> i; 
	}
	return tolower(i);
}

int humanPlayer::makeWager() {
	int wager = -1;
	while (wager < MIN_BET || wager > MAX_BET){
		std::cout << "bet: ";
		std::cin >> wager;
	} 
}

//RANDOM PLAYER IMPLEMENTATIONS
randomPlayer::randomPlayer(std::string name)
	: player(name)
{}

randomPlayer::randomPlayer(std::string name, int purse)
	: player(name, purse)
{}

char randomPlayer::makeMove(card& d) const {
	if (std::rand() % 2 > 0.5)
		return 'h';
	else
		return 's';
}

int player::makeWager() {
	int wager = MIN_BET + (std::rand() % (MAX_BET - MIN_BET));
	m_purse -= wager;
	return wager;
}

// STANDARD PLAYER IMPLEMENTATIONS
standardPlayer::standardPlayer(std::string name)
	: player(name)
{}

standardPlayer::standardPlayer(std::string name, int purse)
	: player(name, purse)
{}

char standardPlayer::makeMove(card& d) const {
	//If the dealer is showing 
	if (getCardVal(d) == 10 || getCardVal(d) == 0) {
		if (getHandVal(getHand()) >= 17 || getHandVal(getHand()) == -1)
			return 's';
	}
	else {
		if (getHandVal(getHand()) >= 12 || getHandVal(getHand()) == -1)
			return 's';
	}
	return 'h';
}

int player::makeWager() {
	int wager = MIN_BET + 10;
	m_purse -= wager;
	return wager;
}
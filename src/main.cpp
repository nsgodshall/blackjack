#include <iostream>

#include "game.h"


int main() {


	std::srand(std::time(NULL));
	//deck longDeck;
	//longDeck.dump();
	//longDeck.shuffleDeck();
	//std::cout << "================= " << std::endl;
	//longDeck.dump();
	game g1(4);
	g1.playGame();

}
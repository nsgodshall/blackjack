#include <iostream>

#include "game.h"
#include "player.h"

int main() {

	std::srand(std::time(NULL));
	//deck longDeck;
	//longDeck.dump();
	//longDeck.shuffleDeck();
	//std::cout << "================= " << std::endl;
	//longDeck.dump();
	game g1(30);
	g1.play();

}


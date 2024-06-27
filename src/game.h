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
  // Initialize a game object wihth a default shoe size = 1. Fills the m_allPlayers vector
  game(int nStandard, int nHuman, int nRandom, int nNaive);
  game(int numPlayers, int shoeSize);
  void play();

private:
  // Clear the dealers hand of any cards, and add two cards to dealers hand, then deal two cards to each player
  void deal();
  // Query each player for what amount to bet
  void setWagers();
  // Superfunction which manages a round from collecting wagers, dealing, querying players for moves, and settling balances after completion of round
  void manageRound();
  // Query each player to hit or to stay
  void playRound();
  void playHand(player* p);
  
  // felt cute, might delete later idk
  void manageRoundVerbose();
  void playRoundVerbose();
  void settleUpVerbose();
  void playHandVerbose(player* p);

  // TODO: Replace this function, this is a placeholder
  void settleUp();
  std::vector<player *> m_allPlayers;
  std::map<player *, int> m_wagers;
  dealer m_dealer;
  deck m_gameDeck;
  int m_shoeSize;
};

#endif // GAME_INCLUDED
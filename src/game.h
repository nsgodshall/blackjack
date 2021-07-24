#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <list>
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
  game(int nStandard, int nHuman, int nRandom, int nNaive);
  game(int numPlaters, int shoeSize);
  void play();

private:
  void deal();
  void setWagers();
  // void manageRound();
  // void playRound();
  // void playHand(player* p);
  
  // felt cute, might delete later idk
  void manageRoundVerbose();
  void setWagersVerbose();
  void playRoundVerbose();
  void settleUpVerbose();
  void playHandVerbose(player* p);

  // TODO: Replace this function, this is a placeholder
  void settleUp();
  std::vector<player*> m_allPlayers;
  std::map<player *, int> m_wagers;
  dealer m_dealer;
  deck m_gameDeck;
  int m_shoeSize;
};

#endif // GAME_INCLUDED
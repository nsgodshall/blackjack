#include "game.h"

game::game(int nStandard, int nHuman, int nRandom, int nNaive)
    : m_gameDeck(DEFAULT_SHOE_SIZE), m_shoeSize(DEFAULT_SHOE_SIZE) {
  // initialize all of the players
  std::string namePlaceHolder;

  // Query program user for names, add them to name vector...
  // for all standard players
  for  (int i = 0; i < nStandard; i++) {
    std::cout << "Enter the name of (Standard) player "
              << m_allPlayers.size() + 1 << ": ";
    std::cin >> namePlaceHolder;
    m_allPlayers.push_back(new standardPlayer(namePlaceHolder));
  }

  // ... for all human players
  for (int i = 0; i < nHuman; i++) {
    std::cout << "Enter the name of (human) player " << m_allPlayers.size() + 1
              << ": ";
    std::cin >> namePlaceHolder;
    m_allPlayers.push_back(new humanPlayer(namePlaceHolder));
  }

  // ... for all random players
  for (int i = 0; i < nRandom; i++) {
    std::cout << "Enter the name of (random) player " << m_allPlayers.size() + 1
              << ": ";
    std::cin >> namePlaceHolder;
    m_allPlayers.push_back(new randomPlayer(namePlaceHolder));
  }

  // ... for all naive players
  for (int i = 0; i < nNaive; i++) {
    std::cout << "Enter the name of (naive) player " << m_allPlayers.size() + 1
              << ": ";
    std::cin >> namePlaceHolder;
    m_allPlayers.push_back(new naivePlayer(namePlaceHolder));
  }

  // shuffle the deck
  m_gameDeck.shuffleDeck();
}

game::game(int numPlayers, int shoeSize)
    : m_gameDeck(shoeSize), m_shoeSize(shoeSize) {
  // initialize all of the players
  std::string namePlaceHolder;

  for (int i = 0; i < numPlayers; i++) {
    std::cout << "Enter the name of player " << i + 1 << ": ";
    std::cin >> namePlaceHolder;
    m_allPlayers.push_back(new randomPlayer(namePlaceHolder));
    m_wagers[m_allPlayers.back()] = 0;
  }
  // shuffle the deck
  m_gameDeck.shuffleDeck();
}

void game::play() {
  for (int i = 0; i < 10; i++) {
    manageRoundVerbose();
  }
  //std::cerr << m_allPlayers[0]->getPurse() << " " << m_allPlayers[1]->getPurse();
}


void game::manageRound() {

  // If the current deck size is smaller than the set minimum deck size, create a new deck
  if (m_gameDeck.size() < MIN_DECK_SIZE) {
    m_gameDeck = deck(m_shoeSize);
  }
  
  // conduct the four stages of a round
  setWagers();
  deal();
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

void game::setWagers() {
  for (player *p : m_allPlayers) {
    int wager = p->makeWager();
    // std::cerr << p->getName() << ": $" << wager << std::endl;
    m_wagers[p] = wager;
  }
}

void game::playRound() {
  card c;

  for (player *p : m_allPlayers) {
        // check if player can split
        // if so
    if (p->getHand().front().val == p->getHand().back().val && p->splitQuery()){
      std::cerr << "split!" << std::endl;
      std::vector<card> oldHand = p->getHand();
      p->splitHand();
      p->clearHand();
      p->addCard(oldHand.front());
      m_gameDeck.drawCard(c);
      p->addCard(c);
      playHand(p);
      p->clearHand();
      p->addCard(oldHand.back());
      m_gameDeck.drawCard(c);
      p->addCard(c);      
    }
    playHand(p);
  }

  while (m_dealer.makeMove() == 'h') {
    m_gameDeck.drawCard(c);
    m_dealer.addCard(c);
  }
}

void game::playHand(player* p){
  card c;
  while (p->makeMove(m_dealer.getHand().back()) == 'h') {
    m_gameDeck.drawCard(c);
    p->addCard(c);
    std::cout << "Card Dealt "; 
    p->dumpLastCard();
    std::cout << std::endl;
    std::cout << "New Hand Value: " << getHandVal(p->getHand());
    if (getHandVal(p->getHand()) == -1) {
      break;
    }
  }
}

void game::settleUp() {
  std::vector<player *> winners;
  std::vector<player *> losers;
  std::vector<player *> ties;
  int dealerVal = getHandVal(m_dealer.getHand());

  // dealer busted
  if (dealerVal == -1) {
    for (player *p : m_allPlayers) {
      // If player has not busted but the dealer has, they are a winner
      if (getHandVal(p->getHand()) != -1)
        p->addMoney(2 * m_wagers[p]);
      // If the player busts, they are a loser
    }
  } else {
    for (player *p : m_allPlayers) {
      int pHand = getHandVal(p->getHand());
      if (pHand > dealerVal)
        p->addMoney(2 * m_wagers[p]);
      else if (pHand == dealerVal)
        p->addMoney(m_wagers[p]);
    }
  }

  // reset wagers
  std::map<player *, int>::iterator it;
  for (it = m_wagers.begin(); it != m_wagers.end(); it++) {
    it->second = 0;
  }
}

// VERBOSE FUNCTIONS

void game::manageRoundVerbose() {
  if (m_gameDeck.size() < MIN_DECK_SIZE) {
    std::cout << "SHUFFLING" << std::endl;
    m_gameDeck = deck(m_shoeSize);
  }
  std::cout << std::endl << "=== MAKE  BETS ===";
  setWagers();
  std::cout << std::endl << "====== DEAL ======" << std::endl;
  deal();
  std::cout << "DEALER: "
            << "XX, " << m_dealer.getHand().back().suit
            << m_dealer.getHand().back().val << std::endl;

  for (player *p : m_allPlayers) {
    std::cout << p->getName() << ": ";
    p->dumpHand();
    std::cout << std::endl;
  }
  std::cout << std::endl << "=== BEGIN PLAY ===" << std::endl;
  playRoundVerbose();
  settleUpVerbose();
}

void game::playRoundVerbose() {
  card c;
  for (player *p : m_allPlayers) {
    std::cout << std::endl << p->getName() << "'s turn: " << std::endl;
    std::cout << "HAND: ";
    p->dumpHand();
    std::cout << " (Val is: " << getHandVal(p->getHand()) << ")";
    std::cout << std::endl;
    if (p->getHand().front().val == p->getHand().back().val && p->splitQuery()){
      std::cerr << "split!" << std::endl;
      std::vector<card> oldHand = p->getHand();
      p->clearHand();
      p->addCard(oldHand.front());
      m_gameDeck.drawCard(c);
      p->addCard(c);
      playHand(p);
      p->clearHand();
      p->addCard(oldHand.back());
      m_gameDeck.drawCard(c);
      p->addCard(c);      
    }
    playHand(p);

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

void game::playHandVerbose(player* p){
  card c;
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

void game::settleUpVerbose() {
  std::vector<player *> winners;
  std::vector<player *> losers;
  std::vector<player *> ties;
  int dealerVal = getHandVal(m_dealer.getHand());

  // dealer busted
  if (dealerVal == -1) {
    for (player *p : m_allPlayers) {
      if (getHandVal(p->getHand()) != -1)
        winners.push_back(p);
      else
        losers.push_back(p);
    }
  } else {
    for (player *p : m_allPlayers) {
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

  if (winners.size() != 0){
    std::cerr << std::endl << "WINNERS: " << std::endl;
    for (player *w : winners) {
      w->addMoney(2 * m_wagers[w]);
      std::cerr << w->getName() << " $" << w->getPurse() - m_wagers[w]
                << " ----> $" << w->getPurse() << std::endl;
    }             
  }

  std::cerr << std::endl << "LOSERS: " << std::endl;
  for (player *l : losers) {
    std::cerr << l->getName() << ": " << l->getPurse() + m_wagers[l]
              << " ----> " << l->getPurse() << std::endl;
  }
  std::cerr << std::endl << "TIES: " << std::endl;
  for (player *t : ties) {
    t->addMoney(m_wagers[t]);
    std::cerr << t->getName() << ": " << t->getPurse() << " ----> "
              << t->getPurse() << std::endl;
  }

  std::map<player *, int>::iterator it;
  for (it = m_wagers.begin(); it != m_wagers.end(); it++) {
    it->second = 0;
  }
  std::cerr << std::endl;
}
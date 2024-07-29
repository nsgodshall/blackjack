#ifndef DECK_INCLUDED
#define DECK_INCLUDED

#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

#include "card.h"

class deck {
public:
  // Initialize a deck with a shoe size of 1
  deck();

  // Initialize a deck with a shoe size of n
  deck(int shoeSize);

  // ACCESSORS
  // return the amount of cards that still could be drawn in the deck
  int size() const { return m_nCards; }

  // MUTATORS

  // Change the order of the cards in the deck randomly
  bool shuffleDeck();

  // return a card to be played and remove that card from the deck
  bool drawCard(card &c);

  // print all cards in the deck to screen, for debugging purposes
  void dump();

private:
  std::vector<card> m_cards;
  int m_nCards;
};

#endif // DECK_INCLUDED

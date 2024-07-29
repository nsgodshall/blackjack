#include "deck.h"

deck::deck() : m_nCards(0) {
  std::vector<char> suits = {'S', 'C', 'H', 'D'};
  std::vector<char> cardValues = {'2', '3', '4', '5', '6', '7', '8',
                                  '9', 'T', 'J', 'Q', 'K', 'A'};

  for (int i = 0; i < suits.size(); i++) {
    for (int j = 0; j < cardValues.size(); j++) {
      card added;
      added.suit = suits[i];
      added.val = cardValues[j];
      m_cards.push_back(added);
      m_nCards++;
    }
  }
}

deck::deck(int shoeSize) : m_nCards(0) {
  std::vector<char> suits = {'S', 'C', 'H', 'D'};
  std::vector<char> cardValues = {'2', '3', '4', '5', '6', '7', '8',
                                  '9', 'T', 'J', 'Q', 'K', 'A'};
  for (int i = 0; i < shoeSize; i++) {
    for (int i = 0; i < suits.size(); i++) {
      for (int j = 0; j < cardValues.size(); j++) {
        card added;
        added.suit = suits[i];
        added.val = cardValues[j];
        m_cards.push_back(added);
        m_nCards++;
      }
    }
  }
}

bool deck::shuffleDeck() {
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(m_cards.begin(), m_cards.end(), g);
  return 1;
}

// convert return type to bool wheter a card can be successfully drawns
bool deck::drawCard(card &c) {
  if (m_nCards == 0)
    return false;

  c = m_cards.back();
  m_cards.pop_back();
  m_nCards--;
  return true;
}

void deck::dump() {
  for (int i = 0; i < m_cards.size(); i++) {
    std::cerr << m_cards[i].suit << " " << m_cards[i].val << std::endl;
  }
}
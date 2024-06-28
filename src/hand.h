#ifndef HAND_INCLUDED
#define HAND_INCLUDED

#include <vector>

#include "card.h"

class hand{
public:
    hand() : m_handSize(0) {;}


// ACCESSORS
    int getNumCards() const;
    std::vector<card *> getCardsInHand() const;
    card* getLastCard() const;
    int getHandVal() const;
    
// MUTATORS
    card* addCardToHand(card* addedCard);
    int clearHand();


private:
    int m_handSize;


    std::vector<card *> m_hand;

};





#endif //HAND_INCLUDED
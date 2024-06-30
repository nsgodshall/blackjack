#include "hand.h"
#include "player.h"
#include "utilities.h"


// ACCESSORS
    int hand::getNumCards() const{
        return m_handSize;
    }
    std::vector<card *> hand::getCardsInHand() const{
        return m_hand;
    }
    card* hand::getLastCard() const{
        return m_hand.back();
    }
    int hand::getHandVal() const{
        return calcHandVal(m_hand);
    }
    
// MUTATORS
    card* hand::addCardToHand(card* addedCard){
        m_hand.push_back(addedCard);
        m_handSize++;
        return addedCard;
    }
    int hand::clearHand(){return 0;}
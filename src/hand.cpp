#include "hand.h"
#include "player.h"




// ACCESSORS
    int hand::getNumCards() const{

    }
    std::vector<card *> hand::getCardsInHand() const;
    card* hand::getLastCard() const;
    int hand::getHandVal() const;
    
// MUTATORS
    card* hand::addCardToHand(card* addedCard){
        m_hand.push_back(addedCard);
        return addedCard;
    }
    int hand::clearHand();
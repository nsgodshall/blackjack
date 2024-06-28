#include "hand.h"
#include "player.h"


// ACCESSORS
    int hand::getNumCards() const{
        return 0;
    }
    std::vector<card *> hand::getCardsInHand() const{
        std::vector<card *> v;
        v.push_back(nullptr);
        return v;
    }
    card* hand::getLastCard() const{
        return nullptr;
    }
    int hand::getHandVal() const{
        return 0;
    }
    
// MUTATORS
    card* hand::addCardToHand(card* addedCard){
        m_hand.push_back(addedCard);
        return addedCard;
    }
    int hand::clearHand(){return 0;}
#include "hand.h"
#include "player.h"


card* hand::addCardToHand(card* addedCard){
    m_hand.push_back(addedCard);
    return addedCard;
}
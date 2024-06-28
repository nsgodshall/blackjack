#ifndef HAND_INCLUDED
#define HAND_INCLUDED

#include <vector>

#include "card.h"

class hand{
public:
    hand() {;}

    card* addCardToHand(card* addedCard);





private:
    std::vector<card *> m_hand;

};





#endif //HAND_INCLUDED
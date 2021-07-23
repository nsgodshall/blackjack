#include "utilities.h"

int getCardVal(const card &c) {
  if (c.val >= 50 && c.val <= 57)
    return c.val - 48;
  if (c.val == 'A')
    return 0;
  else
    return 10;
}

int getHandVal(const std::vector<card> &hand) {
  int sum(0);
  std::vector<card>::const_iterator it = hand.begin();
  for (it; it != hand.end(); it++) {
    if (it->val >= 50 && it->val <= 57)
      sum += it->val - 48;
    else if (it->val == 'A') {
      sum += 11;
    } else {
      sum += 10;
    }
  }

  if (sum > 21){
    for(it = hand.begin(); it != hand.end(); it++){
      if(it->val == 'A'){
        sum -= 10; 
        break;
      }
    }
  }

  if (sum > 21)
    return -1;
  
  else if (sum == 21) {
    if (hand.size() == 2)
      return 0;
  }
  return sum;
}
#include <iostream>
#include <cassert>

#include "game.h"
#include "hand.h"
#include "utilities.h"

#include "test.h"

void testHandVal(){
  card c;
  c.suit = 'S';
  c.val = 'J';

  player p("debug");
  p.addCard(c);

  c.val = 'A';
  p.addCard(c);

  assert(calcHandVal(p.getHand()) == 0);
  c.val = '2';
  p.addCard(c);
  assert(calcHandVal(p.getHand()) == 13);

  c.val = '8';
  p.addCard(c);
  assert(calcHandVal(p.getHand()) == 21);
}

void testHandClass(){
  test_hand_class();
  std::cout << "all tests passed." << std::endl;
}

int main() {

  testHandClass();
  // game g1(0,3,0,0);
  // g1.play();
}
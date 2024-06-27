#include <iostream>
#include <cassert>

#include "game.h"
#include "utilities.h"

void testHandVal(){
  card c;
  c.suit = 'S';
  c.val = 'J';

  player p("debug");
  p.addCard(c);

  c.val = 'A';
  p.addCard(c);

  assert(getHandVal(p.getHand()) == 0);
  c.val = '2';
  p.addCard(c);
  assert(getHandVal(p.getHand()) == 13);

  c.val = '8';
  p.addCard(c);
  assert(getHandVal(p.getHand()) == 21);
}

int main() {
  game g1(3,0,0,0);
  g1.play();
}
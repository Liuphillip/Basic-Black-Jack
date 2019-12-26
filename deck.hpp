#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <time.h>

class deck{
public:
  deck();
  void newDeck();
  int getCard();
private:
  int cards[52];
};
#endif

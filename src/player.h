#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include <string>
#include <vector>

#include "card.h"
#include "utilities.h"

class player {
public:
  // Initialize a player with a user defined name and and default purse size
  player(std::string name);
  // initialize a player with a user defined purse
  player(std::string, int purse);
  // destructor <Does this need to exist?>
  ~player();

  // ACCESSORS
  std::string getName() const { return m_name; }
  std::vector<card> getHand() const { return m_hand; }
  int getPurse() const { return m_purse; }
  void dumpHand() const;
  void dumpLastCard() const;

  // MUTATORS
  bool addCard(card c);
  void clearHand() { m_hand.clear(); }
  void addMoney(int amt) { m_purse += amt; }
  void removeMoney(int amt) { m_purse -= amt; }
  // Move the back element of original hand to be the first element of second hand.
  void splitHand();

  virtual char makeMove() const { return 's'; }
  virtual char makeMove(card &d) const { return 's'; }
  virtual int makeWager();
  virtual bool splitQuery() const { return false; } 

private:
  std::string m_name;
  int m_purse;
  std::vector<card> m_hand;
  std::vector<card> m_splitHand;
};

class dealer : public player {
public:
  dealer();
  virtual char makeMove() const;
};

class humanPlayer : public player {
public:
  humanPlayer(std::string name);
  humanPlayer(std::string name, int purse);
  virtual char makeMove(card &d) const;
  virtual int makeWager();
  virtual bool splitQuery() const;
};

class randomPlayer : public player {
public:
  randomPlayer(std::string name);
  randomPlayer(std::string name, int purse);
  virtual char makeMove(card &d) const;
  virtual int makeWager();
  virtual bool splitQuery() const;
};

class standardPlayer : public player {
public:
  standardPlayer(std::string name);
  standardPlayer(std::string name, int purse);
  virtual char makeMove(card &d) const;
  virtual int makeWager();
  virtual bool splitQuery() const;
};

class naivePlayer : public player {
public:
  naivePlayer(std::string name);
  naivePlayer(std::string name, int purse);
  virtual char makeMove(card &d) const;
  virtual int makeWager();
  virtual bool splitQuery() const;
};
#endif // PLAYER_INCLUDED
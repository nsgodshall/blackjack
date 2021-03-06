#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include <string>
#include <vector>

#include "card.h"
#include "utilities.h"

class player {
public:
  player(std::string name);
  player(std::string, int purse);
  ~player();

  // accessors
  std::string getName() const { return m_name; }
  std::vector<card> getHand() const { return m_hand; }
  int getPurse() const { return m_purse; }
  void dumpHand() const;

  // mutators
  bool addCard(card c);
  void clearHand() { m_hand.clear(); }
  void addMoney(int amt) { m_purse += amt; }
  void removeMoney(int amt) { m_purse -= amt; }

  virtual char makeMove() const { return 's'; }
  virtual char makeMove(card &d) const { return 's'; }
  virtual int makeWager();
  virtual bool splitQuery() const { return false; } 

private:
  std::string m_name;
  int m_purse;
  std::vector<card> m_hand;
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
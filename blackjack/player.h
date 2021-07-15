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

		//accessors
		std::string getName() const { return m_name; }
		std::vector<card> getHand() const { return m_hand; }
		int getPurse() const { return m_purse; }
		void dumpHand() const;

		//mutators
		bool addCard(card c);
		void clearHand() { m_hand.clear(); }
		
		virtual char makeMove() const = 0;
	private:
		std::string m_name;
		int m_purse;
		std::vector<card> m_hand;
};


// TODO: NOT SURE IF DEALER SHOULD BE IT'S OWN CLASS OR BE IMPLEMENTED USING MEMBER FUNCTIONS IN game
class dealer : public player
{
	public:
		dealer();
		char makeMove() const;
};

class randomPlayer : public player
{
	public:
		randomPlayer(std::string name);
		randomPlayer(std::string name, int purse);
		char makeMove() const;
	
};

class standardPlayer : public player
{
	public:
		standardPlayer(std::string name);
		standardPlayer(std::string name, int purse);
		char makeMove() const;

};
#endif //PLAYER_INCLUDED
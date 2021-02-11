// PLAYER.H

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>
using namespace std;

class Player
{
private:
	string _playerName;
	int _playerWins;
	int _playerLosses;

public:
	Player();
	Player(string pName, int pWins, int pLosses);

	void incPlayerWins();
	// pre: none
	// post: _playerWins is now one more than it used to be

	void incPlayerLosses();
	// pre: none
	// post: _playerLosses is now one more than it used to be

	string getPlayerName() const;
	int getPlayerWins() const;
	int getPlayerLosses() const;

	void setPlayerName(string);
	void setPlayerWins(int);
	void setPlayerLosses(int);


};

#endif

// PLAYER.CPP
#include "Player.h"

Player::Player()
	:_playerName(""), _playerWins(0), _playerLosses(0)
	{}

Player::Player(string pName, int pWins, int pLosses)
	: _playerName(pName), _playerWins(pWins), _playerLosses(pLosses)
	{}

void Player::incPlayerWins()
{
	_playerWins++;
}

void Player::incPlayerLosses()
{
	_playerLosses++;
}

string Player::getPlayerName() const
{
	return _playerName;
}

int Player::getPlayerWins() const
{
	return _playerWins;
}

int Player::getPlayerLosses() const
{
	return _playerLosses;
}

void Player::setPlayerName(string pName)
{
	_playerName = pName;
}

void Player::setPlayerWins(int pWins)
{
	_playerWins = pWins;
}

void Player::setPlayerLosses(int pLosses)
{
	_playerLosses = pLosses;
}



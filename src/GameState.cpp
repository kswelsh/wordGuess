// GAMESTATE.CPP
#include "GameState.h"

GameState::GameState(string curWord, string sOfWord, vector<char> lIncorrect, vector<string> wIncorrect, int aLeft)
	: _currentWord(curWord), _stateOfWord(sOfWord), _lettersIncorrectG(lIncorrect), _wordsIncorrectG(wIncorrect), _attemptsLeft(aLeft)
	{}

string GameState::getCurrentWord() const
{
	return _currentWord;
}

string GameState::getStateOfWord() const
{
	return _stateOfWord;
}

vector<char> GameState::getLettersIncorrectG() const
{
	return _lettersIncorrectG;
}

vector<string> GameState::getWordsIncorrectG() const
{
	return _wordsIncorrectG;
}

int GameState::getAttemptsLeft() const
{
	return _attemptsLeft;
}

void GameState::setCurrentWord(string curWord)
{
	_currentWord = curWord;
}

void GameState::setStateOfWord(string sOfWord)
{
	_stateOfWord = sOfWord;
}

void GameState::setLettersIncorrectG(vector<char> lIncorrect)
{
	_lettersIncorrectG = lIncorrect;
}

void GameState::setWordsIncorrectG(vector<string> wIncorrect)
{
	_wordsIncorrectG = wIncorrect;
}

void GameState::setAttemptsLeft(int aLeft)
{
	_attemptsLeft = aLeft;
}

bool GameState::matchUserGuess(string userGuess)
{
	bool playerWin = false;
	if (userGuess.size() > 1)
	{
		if (userGuess == _currentWord)
		{
			_stateOfWord = userGuess;
		}
		else
		{
			_wordsIncorrectG.push_back(userGuess);
		}
	}
	else
	{
		bool correctGuess = false;
		for (int i = 0; _currentWord.size() > i; i++)
		{
			if (userGuess[0] == _currentWord[i])
			{
				_stateOfWord[i] = userGuess[0];
				correctGuess = true;
			}
		}
		if (correctGuess == false)
		{
			_lettersIncorrectG.push_back(userGuess[0]);
		}
	}
	if (_stateOfWord == _currentWord)
	{
		playerWin = true;
	}
	return playerWin;
}


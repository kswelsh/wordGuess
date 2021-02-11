// GAMESTATE.CPP
#include "GameState.h"

GameState::GameState()
	:_currentWord(""), _stateOfWord(""), _attemptsLeft(0)
	{}

GameState::GameState(string curWord, string sOfWord, int aLeft)
	: _currentWord(curWord), _stateOfWord(sOfWord), _attemptsLeft(aLeft)
	{}

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
			_wordsIncorrect.push_back(userGuess);
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
			_lettersIncorrect.push_back(userGuess[0]);
		}
	}
	if (_stateOfWord == _currentWord)
	{
		playerWin = true;
	}
	return playerWin;
}

char GameState::getIncorrectLetter(int location)
{
	if (location < getIncorrectLettersSize())
	{
		return _lettersIncorrect[location];
	}
	else
	{
		cout << "ERROR: Data location out of reach! Returning error code O!" << endl;
		return 'x';
	}
}

string GameState::getIncorrectWord(int location)
{
	if (location < getIncorrectWordsSize())
	{
		return _wordsIncorrect[location];
	}
	else
	{
		cout << "ERROR: Data location out of reach! Returning error code OOR." << endl;
		return "OOR";
	}
}

int GameState::getIncorrectLettersSize() const
{
	return _lettersIncorrect.size();
}

int GameState::getIncorrectWordsSize() const
{
	return _wordsIncorrect.size();
}

void GameState::clearIncorrectLetters()
{
	_lettersIncorrect.clear();
}

void GameState::clearIncorrectWords()
{
	_wordsIncorrect.clear();
}

void GameState::hideStateOfWord()
{
	_stateOfWord = "";
	for (int i = 0; _currentWord.size() > i; i++)
		{
			_stateOfWord.append("-");
		}
}

void GameState::decAttemptsLeft()
{
	if (_attemptsLeft > 0)
	{
		_attemptsLeft--;
	}
	else
	{
		cout << "ERROR: _attemptsLeft was not greater than zero!" << endl;
	}
}

string GameState::getCurrentWord() const
{
	return _currentWord;
}

string GameState::getStateOfWord() const
{
	return _stateOfWord;
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

void GameState::setAttemptsLeft(int aLeft)
{
	_attemptsLeft = aLeft;
}


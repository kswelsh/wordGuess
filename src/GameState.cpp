// GAMESTATE.CPP

#include <string>
#include <vector>
using namespace std;

#include "GameState.h"

GameState::GameState(string curGuess, string sOfWord, vector<char> lIncorrect, vector<string> wIncorrect, int aLeft)
	: _currentWordGuessed(curGuess), _stateOfWord(sOfWord), _lettersIncorrectG(lIncorrect), _wordsIncorrectG(wIncorrect), _attemptsLeft(aLeft)
	{}

string GameState::getCurrentGuess() const
{
	return _currentWordGuessed;
}

string GameState::getWordState() const
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

void GameState::setCurrentGuess(string curGuess)
{
	_currentWordGuessed = curGuess;
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

string GameState::matchUserGuess()
{

}


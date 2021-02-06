// GAMESTATE.H

#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

#include <string>
#include <vector>
#include <iostream> // DOINT KNOW IF NEEDED YET
using namespace std;

class GameState
{
private:
	string _currentWord;
	string _stateOfWord;
	vector<char> _lettersIncorrectG;
	vector<string> _wordsIncorrectG;
	int _attemptsLeft;

public:
	GameState(){}
	GameState(string curGuess, string sOfWord, vector<char> lIncorrect, vector<string> wIncorrect, int aLeft);

	string getCurrentWord() const;
	string getStateOfWord() const;
	vector<char> getLettersIncorrectG() const;
	vector<string> getWordsIncorrectG() const;
	int getAttemptsLeft() const;

	void setCurrentWord(string);
	void setStateOfWord(string);
	void setLettersIncorrectG(vector<char>);
	void setWordsIncorrectG(vector<string>);
	void setAttemptsLeft(int);

	bool matchUserGuess(string);

};

#endif

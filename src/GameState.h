// GAMESTATE.H

#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class GameState
{
private:
	string _currentWord;
	string _stateOfWord;
	vector<char> _lettersIncorrect;
	vector<string> _wordsIncorrect;
	int _attemptsLeft;

	void matchIfLetter(string);
	// pre: parm must be a single letter string
	// post: tests if provided letter exists in _currentWord and if so, replaces corresponding empty space in _stateOfWord with provided letter
	//		 if no match, adds provided letter to _lettersIncorrect

	void matchIfWord(string);
	// pre: parm can be any length string (no spaces)
	// post: tests if passed word is _currentWord, if so, replaces _stateOfWord with provided word
	//  	 if no match, adds provided word to _wordsIncorrect

public:
	GameState();
	GameState(string curWord, string sOfWord, int aLeft);

	bool matchUserGuess(string);
	// pre: parm must be word with no spaces or a single letter
	// post: returns true if player wins, false if yet to win. updates _stateOfWord if users guess was right. updates _lettersIncorrect
	//       or _wordsIncorrect if user guess was wrong

	char getIncorrectLetter(int);
	// pre: parm must be subscript location wanted, parm must be a valid location (in reach)
	// post: returns data at provided location

	string getIncorrectWord(int);
	// pre: parm must be subscript location wanted, parm must be a valid location (in reach)
	// post: returns data at provided location

	int getIncorrectLettersSize() const;
	// pre: none
	// post: returns the size of the _incorrectLetters vector

	int getIncorrectWordsSize() const;
	// pre: none
	// post: returns the size of the _incorrectWords vector

	void clearIncorrectLetters();
	// pre: none
	// post: destroys everything in the _incorrectLetters vector

	void clearIncorrectWords();
	// pre: none
	// post: destroys everything in the _incorrectWords vector

	void hideStateOfWord();
	// pre: _currentWord must hold a value
	// post: for every letter of _currentWord, _stateOfWord now holds a "-"

	void decAttemptsLeft();
	// pre: _attemptsLeft must be greater than 0
	// post: _attemptsLeft is now 1 less

	string getCurrentWord() const;
	string getStateOfWord() const;
	int getAttemptsLeft() const;

	void setCurrentWord(string);
	void setStateOfWord(string);
	void setAttemptsLeft(int);

};

#endif

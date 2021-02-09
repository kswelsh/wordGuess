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
	GameState(string curWord, string sOfWord, vector<char> lIncorrect, vector<string> wIncorrect, int aLeft);

	string getCurrentWord() const;
	string getStateOfWord() const;
	int getAttemptsLeft() const;

	void setCurrentWord(string);
	void setStateOfWord(string);
	void setAttemptsLeft(int);

	bool matchUserGuess(string);
	// pre: parm must be word or letter user guesses
	// post: if guessed letter and wrong: _lettersIncorrectG now holds said letter (returns FALSE)
	//       if guessed word and wrong: _wordsIncorrectG now holds said word (returns FALSE)
	//       if guessed letter and correct: _stateOfWord now has said letter visible
	//		 (returns FALSE if word not yet complete, TRUE if word is completed)
	//   	 if guessed word correct, entire word now visible (returns TRUE)

	void printLettersIncorrectG();
	// pre: none
	// post: prints out all letters user has incorrectly guessed in current game

	void printWordsIncorrectG();
	// pre: none
	// post: prints out all words user has incorrectly guessed in current game
};

#endif

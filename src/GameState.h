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

public:
	GameState();
	GameState(string curWord, string sOfWord, int aLeft);

	bool matchUserGuess(string);
	// pre: parm must be word or letter user guesses
	// post: if guessed letter and wrong: _lettersIncorrectG now holds said letter (returns FALSE)
	//       if guessed word and wrong: _wordsIncorrectG now holds said word (returns FALSE)
	//       if guessed letter and correct: _stateOfWord now has said letter visible
	//		 (returns FALSE if word not yet complete, TRUE if word is completed)
	//   	 if guessed word correct, entire word now visible (returns TRUE)

	char getIncorrectLetter(int);
	// pre: parm must be subscript location wanted, parm must be a valid location
	// post: returns data at provided location

	string getIncorrectWord(int);
	// pre: parm must be subscript location wanted, parm must be a valid location
	// post: returns data at provided location

	int getIncorrectLettersSize() const;
	// pre: none
	// post: returns the size of the _incorrectLetters vector

	int getIncorrectWordsSize() const;
	// pre: none
	// post: returns the size of the _incorrectWords vector

	void clearIncorrectLetters();
	// pre: none
	// post: deletes everything in the _incorrectLetters vector

	void clearIncorrectWords();
	// pre: none
	// post: deletes everything in the _incorrectWords vector

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

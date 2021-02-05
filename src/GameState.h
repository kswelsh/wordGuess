// GAMESTATE.H

#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

class GameState
{
private:
	string _currentWordGuessed;
	string _stateOfWord;
	vector<char> _lettersIncorrectG;
	vector<string> _wordsIncorrectG;
	int _attemptsLeft;

public:
	GameState(){}
	GameState(string curGuess, string sOfWord, vector<char> lIncorrect, vector<string> wIncorrect, int aLeft);

	string getCurrentGuess() const;
	string getWordState() const;
	vector<char> getLettersIncorrectG() const;
	vector<string> getWordsIncorrectG() const;
	int getAttemptsLeft() const;

	void setCurrentGuess(string);
	void setStateOfWord(string);
	void setLettersIncorrectG(vector<char>);
	void setWordsIncorrectG(vector<string>);
	void setAttemptsLeft(int);

	string matchUserGuess();

};

#endif

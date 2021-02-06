//============================================================================
// Name        : wordGuessAssignment.cpp
// Author      : Kyle Welsh
// Version     : N/A
// Copyright   : N/A
// Description : This C++ program creates a Word Guess game for the user.
//============================================================================/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Dictionary.h"
#include "Player.h"
#include "GameState.h"

int main()
{
	Dictionary d;
	Player p;
	GameState g;

	d.populateWithConsole();
	cout << d.accessRandomWord() << endl;


	/*
	g.setCurrentWord("hello");
	g.setStateOfWord("-----");
	g.matchUserGuess("help");
	g.matchUserGuess("v");
	g.matchUserGuess("hey");
	g.matchUserGuess("uh");
	g.matchUserGuess("t");
	g.matchUserGuess("e");
	g.matchUserGuess("l");
	vector<string> wInc = g.getWordsIncorrectG();
	vector<char> lInc = g.getLettersIncorrectG();
	for (int i = 0; wInc.size() > i; i++)
	{
		cout << wInc[i] << endl;
	}
	for (int i = 0; lInc.size() > i; i++)
	{
		cout << lInc[i] << endl;
	}

	cout << g.getStateOfWord() << endl;


	p.setPlayerName("kyle");
	p.setPlayerWins(3);
	p.setPlayerLosses(2);
	cout << p.getPlayerName() << endl;
	cout << p.getPlayerWins() << endl;
	cout << p.getPlayerLosses() << endl;
	*/


	return 0;
}

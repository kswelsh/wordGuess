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

	d.populateWithFile();


	d.accessRandomWord();
	g.setCurrentWord("hello");
	g.setStateOfWord("-----");
	g.matchUserGuess("help");
	g.matchUserGuess("v");
	g.matchUserGuess("hey");
	g.matchUserGuess("uh");
	g.matchUserGuess("t");
	g.matchUserGuess("e");
	g.matchUserGuess("l");
	g.matchUserGuess("p");
	g.matchUserGuess("z");
	g.matchUserGuess("m");
	g.matchUserGuess("u");

	cout << g.getStateOfWord() << endl;
	g.printLettersIncorrectG();
	g.printWordsIncorrectG();
	cout << "test" << endl;

	/*
	p.setPlayerName("kyle");
	p.setPlayerWins(3);
	p.setPlayerLosses(2);
	cout << p.getPlayerName() << endl;
	cout << p.getPlayerWins() << endl;
	cout << p.getPlayerLosses() << endl;
	*/


	return 0;
}

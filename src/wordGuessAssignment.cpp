//============================================================================
// Name        : wordGuessAssignment.cpp
// Author      : Kyle Welsh
// Version     : N/A
// Copyright   : N/A
// Description : This C++ program creates a Word Guess game for the user.
//============================================================================

#include <iostream>
#include <vector> // ASK ABOUT THIS
#include <string>

using namespace std;

#include "Dictionary.h"
#include "Player.h"
#include "GameState.h"

int main()
{
	Dictionary d;
	Player p;

	p.setPlayerName("kyle");
	p.setPlayerWins(3);
	p.setPlayerLosses(2);
	cout << p.getPlayerName() << endl;
	cout << p.getPlayerWins() << endl;
	cout << p.getPlayerLosses() << endl;

	d.populateWithFile();

	return 0;
}

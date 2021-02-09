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
	Dictionary gameDictionary;
	Player gameUser;
	GameState game;
	string userPlay;
	string randomWord;
	string localCurrentWord;
	string hiddenRandomWord = "";
	string userGuess;
	int userPopChoice;
	bool playerWin = false;

	cout << "1) Through File" << endl;
	cout << "2) Through User Input" << endl;
	cout << "Type the corresponding number to choose how to populate the game dictionary:" << endl;
	cin >> userPopChoice;

	if (userPopChoice == 1)
	{
		gameDictionary.populateWithFile();
	}
	else if (userPopChoice == 2)
	{
		gameDictionary.populateWithConsole();
	}
	else
	{
		cout << "ERROR: Invalid input; program will not run correctly.";
	}

	cout << "Would you like to play the word guess game? (Type 'y' for yes OR 'n' for no): " << endl;
	cin >> userPlay;
	while (userPlay == "y" || userPlay == "Y")
	{
		randomWord = gameDictionary.accessRandomWord();
		game.setCurrentWord(randomWord);
		localCurrentWord = game.getCurrentWord();
		game.setAttemptsLeft(localCurrentWord.size());
		for (int i = 0; localCurrentWord.size() > i; i++)
		{
			hiddenRandomWord.append("-");
		}
		game.setStateOfWord(hiddenRandomWord);

		while (game.getAttemptsLeft() != 0 && playerWin == false)
		{
			cout << "You have " << game.getAttemptsLeft() << " attempt(s) left!" << endl;
			game.printLettersIncorrectG();
			game.printWordsIncorrectG();
			cout << "Current Word: " << game.getStateOfWord() << endl;
			cout << "Guess a letter or a word: " << endl;
			cin >> userGuess;
			playerWin = game.matchUserGuess(userGuess);
			game.setAttemptsLeft(game.getAttemptsLeft()-1);
		}

		if(playerWin == true)
		{
			cout << "Nice! You Win!" << endl;
			cout << "The correct word was " << game.getCurrentWord() << "." << endl;
			gameUser.setPlayerWins(gameUser.getPlayerWins()+1);
		}
		else
		{
			cout << "Sorry... You Lose!" << endl;
			cout << "The correct word is " << game.getCurrentWord() << "." << endl;
			gameUser.setPlayerLosses(gameUser.getPlayerLosses()+1);
		}

		cout << "Would you like to play the word guess game? (Type 'y' for yes OR 'n' for no): " << endl;
		cin >> userPlay;
	}

	cout << "You ended with " << gameUser.getPlayerWins() << " win(s) and " << gameUser.getPlayerLosses() << " loss(es)!" << endl;

	return 0;
}

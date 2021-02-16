//============================================================================
// Name        : wordGuessAssignment.cpp (HOMEWORK 1)
// Author      : Kyle Welsh
// Description : This C++ program creates a Word Guess game for the user
//				 to play. It includes three classes to run the program.
//============================================================================

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Dictionary.h"
#include "Player.h"
#include "GameState.h"

void postGuessDisplay(GameState &gInstance)
// pre: parm must be the game in which user wants to display
// post: outputs current attempts left, incorrect letters, and incorrect words
{
	cout << endl << "You have " << gInstance.getAttemptsLeft() << " attempt(s) left!" << endl;
	cout << "Current incorrect letters: ";
	for (int i = 0; i < gInstance.getIncorrectLettersSize(); i++)
	{
		cout << gInstance.getIncorrectLetter(i) << " ";
	}
	cout << endl;
	cout << "Current incorrect words: ";
	for (int i = 0; i < gInstance.getIncorrectWordsSize(); i++)
	{
		cout << gInstance.getIncorrectWord(i) << " ";
	}
	cout << endl;
}
void playerStatusUpdate(Player &pData, GameState &gInstance, bool &playerWin)
// pre: must pass in player data user wants to update, current game instance, and value of if the player has won or not
// post: displays if player won or lost, increments players total wins or losses, and resets playerWin variable
{
	if(playerWin == true)
	{
		cout << endl << "Nice! You Win! The correct word was " << gInstance.getCurrentWord() << "." << endl;
		pData.incPlayerWins();
		playerWin = false;
	}
	else
	{
		cout << endl << "Sorry... You Lose! The correct word is " << gInstance.getCurrentWord() << "." << endl;
		pData.incPlayerLosses();
	}
}
void populate(Dictionary &dData)
// pre: parm must be the dictionary you want to populate
// post: dictionary is populated from either a chosen file or chosen user words
{
	string fileChoice;
	int userPopChoice;

	cout << "=========================" << endl << "|    DICTIONARY MENU    |" << endl << "=========================" << endl;
	cout << "| 1) Through File       |" << endl << "| 2) Through User Input |" << endl << "=========================" << endl;
	cout << "Type a number listed to choose how to populate the dictionary:" << endl;
	cin >> userPopChoice;
	if (userPopChoice == 1)
	{
		cout << "Enter the name of the file you are using: " << endl;
		cin >> fileChoice;
		dData.populateWithFile(fileChoice);
	}
	else
	{
		dData.populateWithConsole();
	}
}

void spaceDelimit(string word)
// pre: for this function to perform correctly; parm word must be at least 2 characters
// post: given word is printed out as space delimited
{
	for (int i = 0; i < word.size(); i++)
	{
		cout << word[i] << " ";
	}
}

int main()
{
	Dictionary dictionaryData;
	Player playerData;
	GameState gameInstance;

	string randomWord;
	string userGuess;
	string userPlayChoice;
	bool playerWin;

	populate(dictionaryData);

	cout << "Would you like to play the word guess game? (Type 'y' for yes OR 'n' for no): " << endl;
	cin >> userPlayChoice;
	while (userPlayChoice == "y" || userPlayChoice == "Y")
	{
		randomWord = dictionaryData.accessRandomWord();
		gameInstance.setCurrentWord(randomWord);
		gameInstance.setAttemptsLeft(randomWord.size());
		gameInstance.hideStateOfWord();
		while (gameInstance.getAttemptsLeft() != 0 && playerWin == false)
		{
			cout << "Current Word: ";
			spaceDelimit(gameInstance.getStateOfWord());
			cout << endl;
			cout << "Guess a letter or word: " << endl;
			cin >> userGuess;
			playerWin = gameInstance.matchUserGuess(userGuess);
			gameInstance.decAttemptsLeft();

			if (playerWin == false && gameInstance.getAttemptsLeft() > 0)
			{
				postGuessDisplay(gameInstance);
			}
		}
		gameInstance.clearIncorrectLetters();
		gameInstance.clearIncorrectWords();

		playerStatusUpdate(playerData, gameInstance, playerWin);

		cout << "Would you like to play the word guess game? (Type 'y' for yes OR 'n' for no): " << endl;
		cin >> userPlayChoice;
	}

	cout << "You ended with " << playerData.getPlayerWins() << " win(s) and " << playerData.getPlayerLosses() << " loss(es)!" << endl;

	return 0;
}

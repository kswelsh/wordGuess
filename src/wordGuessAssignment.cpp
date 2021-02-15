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

void spaceDelimit(string word)
// pre: for this function to perform correctly; passed word must be at least 2 characters
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
	string userPlayChoice;
	string fileChoice;
	string randomWord;
	string userGuess;
	bool playerWin;
	int userPopChoice;

	cout << "=========================" << endl << "|    DICTIONARY MENU    |" << endl << "=========================" << endl;
	cout << "| 1) Through File       |" << endl << "| 2) Through User Input |" << endl << "=========================" << endl;
	cout << "Type a number listed to choose how to populate the dictionary:" << endl;
	cin >> userPopChoice;
	if (userPopChoice == 1)
	{
		cout << "Enter the name of the file you are using: " << endl;
		cin >> fileChoice;
		dictionaryData.populateWithFile(fileChoice);
	}
	else
	{
		dictionaryData.populateWithConsole();
	}

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
				cout << endl << "You have " << gameInstance.getAttemptsLeft() << " attempt(s) left!" << endl;
				cout << "Current incorrect letters: ";
				for (int i = 0; i < gameInstance.getIncorrectLettersSize(); i++)
					{
						cout << gameInstance.getIncorrectLetter(i) << " ";
					}
				cout << endl;
				cout << "Current incorrect words: ";
				for (int i = 0; i < gameInstance.getIncorrectWordsSize(); i++)
					{
						cout << gameInstance.getIncorrectWord(i) << " ";
					}
				cout << endl;
			}
		}

		gameInstance.clearIncorrectLetters();
		gameInstance.clearIncorrectWords();

		if(playerWin == true)
		{
			cout << endl << "Nice! You Win! The correct word was " << gameInstance.getCurrentWord() << "." << endl;
			playerData.incPlayerWins();
			playerWin = false;
		}
		else
		{
			cout << endl << "Sorry... You Lose! The correct word is " << gameInstance.getCurrentWord() << "." << endl;
			playerData.incPlayerLosses();
		}

		cout << "Would you like to play the word guess game? (Type 'y' for yes OR 'n' for no): " << endl;
		cin >> userPlayChoice;
	}

	cout << "You ended with " << playerData.getPlayerWins() << " win(s) and " << playerData.getPlayerLosses() << " loss(es)!" << endl;

	return 0;
}

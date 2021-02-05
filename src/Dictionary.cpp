// DICTIONARY.CPP

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <time.h>
using namespace std;

#include "Dictionary.h"

Dictionary::Dictionary(vector<string> dWords)
	: _dictionaryWords(dWords)
	{}

void Dictionary::populateWithConsole()
{
	// User Input?
}

void Dictionary::populateWithFile()
{
	string wordInput;
	ifstream inFile("dictionaryData.txt");
	if (!inFile)
	{
		cout << "Error opening file! Exiting program." << endl;
		exit(-1);
	}
	inFile >> wordInput;
	while (!inFile.eof())
	{
		_dictionaryWords.push_back(wordInput);
		inFile >> wordInput;
	}
}

string Dictionary::accessRandomWord()
{
	string randomWord;
	int wordSelector;

	srand (time(NULL));
	wordSelector = rand() % _dictionaryWords.size();
	randomWord = _dictionaryWords[wordSelector]; //CONST SECURITY???

	cout << _dictionaryWords.size() << endl; // TEST
	cout << randomWord << endl; // TEST
	cout << wordSelector << endl; // TEST

	return randomWord;
}

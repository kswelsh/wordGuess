// DICTIONARY.CPP
#include "Dictionary.h"

Dictionary::Dictionary(vector<string> dWords)
	: _dictionaryWords(dWords)
	{}

void Dictionary::populateWithConsole()
{
	string wordInput;

	cout << "Enter a word to add to the dictionary (type 'e' to exit): ";
	cin >> wordInput;

	while (wordInput != "e" && wordInput != "E")
	{
		_dictionaryWords.push_back(wordInput);
		cout << "Enter a word to add to the dictionary (type 'e' to exit): ";
		cin >> wordInput;
	}
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

	// cout << _dictionaryWords.size() << endl; // TEST
	// cout << randomWord << endl; // TEST
	// cout << wordSelector << endl; // TEST

	for (int i = 0; _dictionaryWords.size() > i; i++) // TEST
		{
			cout << _dictionaryWords[i] << endl;
		}

	return randomWord;
}

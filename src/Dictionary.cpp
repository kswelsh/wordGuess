// DICTIONARY.CPP
#include "Dictionary.h"

Dictionary::Dictionary(vector<string> dWords)
	: _dictionaryWords(dWords)
	{}

void Dictionary::populateWithConsole()
{
	string wordInput;

	cout << "Enter a word to add to the dictionary (type 'e' to exit): " << endl;
	cin >> wordInput;

	while (wordInput != "e" && wordInput != "E")
	{
		_dictionaryWords.push_back(wordInput);
		cout << "Enter a word to add to the dictionary (type 'e' to exit): " << endl;
		cin >> wordInput;
	}
}

void Dictionary::populateWithFile(string fileName)
{
	string wordInput;

	ifstream inFile(fileName);
	if (!inFile)
	{
		cout << "ERROR: Failed opening file! Exiting program." << endl;
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
	randomWord = _dictionaryWords[wordSelector];

	return randomWord;
}

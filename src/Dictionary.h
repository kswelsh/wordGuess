// DICTIONARY.H

#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <time.h>
using namespace std;

class Dictionary
{
private:
	vector<string> _dictionaryWords;

public:
	Dictionary(){}
	Dictionary(vector<string> dWords);

	void populateWithConsole();
	void populateWithFile();
	string accessRandomWord();
};

#endif

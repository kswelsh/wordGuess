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
	// pre: none
	// post: dictionary populated with user inputed word(s)

	void populateWithFile();
	// pre: none
	// post: dictionary populated with word(s) from chosen file

	string accessRandomWord();
	// pre: none
	// post: returns random word from dictionary
};

#endif

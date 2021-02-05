// DICTIONARY.H

#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

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

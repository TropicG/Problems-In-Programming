#ifndef WORD_H
#define WORD_H
#include <cstring>
#include <stdexcept>
#include <iostream>


class Word {
private:

	char* word;

public:

	//default constructor
	Word();

	//constructor with one arg
	Word(const char* word);

	//copy constructor
	Word(const Word& other);

	//copy assaingment constructor
	Word& operator=(const Word& other);

	//destructor
	~Word();

	//getting element by index
	char& operator[](const int& index);

	//appending two string and returning a copy
	Word operator+(const Word& other);

	//appending two string
	Word& operator+=(const Word& other);

	//operator for equalness
	bool operator==(const Word& other) const;

	//operator for alphabetical order
	bool operator<(const Word& other) const;

	//setter
	void setWord(const char* word);

	//getter
	char* getWord() const;

	//printing the object
	void print() const;

};




#endif

#include "Word.h"

void Word::setWord(const char* word)
{

	//storing the value returned from strlen for simplier code
	int size = strlen(word);

	//if the size is too long we throw exception
	if (size > 20) {
		throw std::invalid_argument("too long string");
	}

	//deleting the current word
	delete[] this->word;

	//allocating memory enough for the argument and we copy it into the object's member
	this->word = new char[size + 1];
	strcpy_s(this->word, size + 1, word);
}

char* Word::getWord() const
{
	return this->word;
}

void Word::print() const
{

	int size = strlen(this->word);

	for (int i = 0; i < size; ++i) {
		std::cout << this->word[i];
	}


}

Word::Word() : word(nullptr)
{
}

Word::Word(const char* word)
{
	this->setWord(word);
}

Word::Word(const Word& other)
{
	this->setWord(other.getWord());
}

Word& Word::operator=(const Word& other)
{
	if (this != &other) {

		this->setWord(other.getWord());

	}

	return *this;
}

Word::~Word()
{
	delete[] this->word;
}

char& Word::operator[](const int& index)
{
	return this->word[index];
}

Word Word::operator+(const Word& other)
{
	//gets the size of the this->word and the argument's word
	int sizeA = strlen(this->getWord()), sizeB = strlen(other.getWord());

	//if the two sizes are greater than 20 we return default constructor
	if (sizeA + sizeB > 20) {
		return Word();
	}

	//creating enough room for the two strings
	char* helper = new char[sizeA + sizeB + 1];

	//memory allocation check
	if (!helper) {
		throw std::bad_alloc();
	}

	//index for the helper variable
	int index = 0;

	//inputting this->word
	for (int i = 0; i < sizeA; ++i) {
		helper[index] = this->word[i];
		index++;
	}

	//inputting argument's word
	for (int i = 0; i < sizeB; ++i) {
		helper[index] = other.word[i];
		index++;
	}

	//at the end we put the terminated null
	helper[index] = '\0';


	//creating the variable and initializing it with helper
	Word temp(helper);


	delete[] helper;
	return temp;
}

Word& Word::operator+=(const Word& other)
{
	//gets the size of the this->word and the argument's word
	int sizeA = strlen(this->word), sizeB = strlen(other.getWord());

	//creating enough room for the two strings
	char* helper = new char[sizeA + sizeB + 1];

	//index for the helper variable
	int index = 0;

	//inputting this->word
	for (int i = 0; i < sizeA; ++i) {
		helper[index] = this->word[i];
		index++;
	}

	//inputting argument's word
	for (int i = 0; i < sizeB; ++i) {
		helper[index] = other.word[i];
		index++;
	}

	//inputting the terminated null
	helper[index] = '\0';

	//setting helper to this->word
	this->setWord(helper);

	delete[] helper;
	return *this;

}

bool Word::operator==(const Word& other) const
{

	//getting the size of the two strings
	int sizeA = strlen(this->word), sizeB = strlen(other.word);


	//if their size is not the same returns false
	if (sizeA != sizeB) {
		return false;
	}

	//checks everysymbol of the two strings in that index
	//if two symbols are different we return false
	for (int i = 0; i < sizeA; ++i) {
		if (this->word[i] != other.word[i]) {
			return false;
		}
	}


	return true;
}

bool Word::operator<(const Word& other) const
{
	//getting the size of the two strings
	int sizeA = strlen(this->word), sizeB = strlen(other.word);

	//3 different cases; 1st if other.word is smaller than this->word
	//2 if this->word is smaller than other.word
	//3 and if they are the same size
	if (sizeA > sizeB) {

		for (int i = 0; i < sizeB; ++i) {
			if (this->word[i] > other.word[i]) {
				return false;
			}
		}

		return true;

	}
	else if (sizeA < sizeB) {

		for (int i = 0; i < sizeA; ++i) {
			if (this->word[i] > other.word[i]) {
				return false;
			}
		}

		return true;

	}
	else {

		for (int i = 0; i < sizeA; ++i) {
			if (this->word[i] > other.word[i]) {
				return false;
			}
		}

		return true;

	}



}

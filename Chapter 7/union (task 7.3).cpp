#include <iostream>
#include <cstring>
using namespace std;

//checks if a symbol is inside the string
bool inside(const char* string, const char& ch) {

	int size = strlen(string);
	for (int i = 0; i < size; ++i) {
		if (string[i] == ch) {
			return true;
		}
	}

	return false;
}

char* Union(const char* stringA, const char* stringB) {

	//sizes of strignA, stringB
	int sizeA = strlen(stringA), sizeB = strlen(stringB);

	//here we store the united string
	char* unionString = new char[sizeA + sizeB + 1];

	//returns nullptr if the allocation failed
	if (!unionString) {
		return nullptr;
	}

	//used in initializing a symbol on this index in unionString
	int index = 0;

	for (int i = 0; i < sizeA; ++i) {

		//if the symbol is not inside unionString we add the symbol to unionString
		//and we increment index
		if (!inside(unionString, stringA[i])) {
			unionString[index] = stringA[i];
			index++;
		}

	}

	for (int i = 0; i < sizeB; ++i) {

		//if the symbol is not inside unionString we add the symbol to unionString
		//and we increment index
		if (!inside(unionString, stringB[i])) {
			unionString[index] = stringB[i];
			index++;
		}

	}

	//adding the null terminated element
	unionString[index] = '\0';

	return unionString;
}

int main() {

	//here we store the two inputted strings
	char stringA[64], stringB[64];
	cout << "Enter the first string: ";
	cin >> stringA;

	cout << "Enter the second string: ";
	cin >> stringB;

	//pointer to an array allocated in function Union
	char* unionString = Union(stringA, stringB);

	//memory allocation check
	if (!unionString) {
		cout << "Invalid memory allocation!";
		delete[] unionString;
		return -1;
	}

	//printing the united string
	cout << "Printing the union string: ";
	int unionSize = strlen(unionString);
	for (int i = 0; i < unionSize; ++i) {
		cout << unionString[i];
	}


	return 0;
}

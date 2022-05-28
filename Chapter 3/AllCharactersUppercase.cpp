#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;


int main() {

	//here we store the string
	char string[256];
	cout << "Enter your string: ";
	cin >> string;

	//getting the size of the string
	int size = strlen(string);

	cout << "Making all the characters uppercase." << endl;
	cout << "The new string is: ";
	for (int i = 0; i < size; ++i) {

		//assaings the current string character in uppercase
		string[i] = toupper(string[i]);
		cout << string[i];
	}

	return 0;
}

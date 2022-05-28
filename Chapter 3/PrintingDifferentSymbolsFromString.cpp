#include <iostream>
#include <cstring>
using namespace std;


int main() {

	//here we store the string
	char symbols[100];
	cout << "Enter your string: ";
	cin >> symbols;
	cout << endl;

	//getting the size of the string, in order our for to not loop 100 times
	int size = strlen(symbols);

	//printing the numbers
	cout << "Printing all the numbers in your string: ";
	for (int i = 0; i < size; ++i) {

		//if the current symbol is between 0 and 9 it prints it
		if (symbols[i] >= '0' && symbols[i] <= '9') {
			cout << symbols[i] << ", ";
		}
	}
	cout << endl;

	//printing the letters
	cout << "Printing all the lowercase letters in your string: ";
	for (int i = 0; i < size; ++i) {

		//if the current symbol is between a and z prints it
		if (symbols[i] >= 'a' && symbols[i] <= 'z') {
			cout << symbols[i] << ", ";
		}
	}
	cout << endl;

	//printing the rest symbols in our string
	cout << "Printing all the other symbols in your string: ";
	for (int i = 0; i < size; ++i) {

		//if the current symbol is not between a-z and 0-9 prints it
		if (!(symbols[i] >= 'a' && symbols[i] <= 'z') && !(symbols[i] >= '0' && symbols[i] <= '9')) {
			cout << symbols[i] << ", ";
		}
	}

	return 0;
}

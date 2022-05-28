#include <iostream>
#include <cstring>
using namespace std;


int main() {

	//here we will store the string
	char string[100];
	cout << "Enter your string: ";
	cin >> string;

	//getting the size of the string, so we dont loop throught all the string
	int size = strlen(string);

	//we will need this so that we change if the string is not symetric
	bool symetric = true;

	//we use this index so we can see a symbol at the end and at the begining of the string
	int j = size - 1;

	cout << "Your string is: ";
	for (int i = 0; i < size/2; ++i) {

		//if a given symbol of the begining is different than a given symbol at the end
		//we assume that they are on the same distance from the left and the right end of the string
		if (string[i] != string[j]) {
			symetric = false;
			break;
		}

		//we decrement j if the first pair of symbols is equvelent to see the other pairs
		j--;
	}

	cout << symetric;
	return 0;

}

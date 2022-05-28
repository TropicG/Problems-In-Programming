#include <iostream>
#include <cstring>
using namespace std;


int main() {

	//here we will store the two strings
	char string1[100];
	char string2[100];

	cout << "Enter your first string: ";
	cin >> string1;
	cout << endl;

	cout << "Enter you second string: ";
	cin >> string2;
	cout << endl;

	cout << "The longest prefix of the two strings is: ";

	//chossing the size of string1 cuz either string1 is prefix of string2 or the size of string1==string2
	int size = strlen(string1);

	for (int i = 0; i < size; ++i) {
		if (string1[i] != string2[i]) {
			break;
		}

		cout << string1[i];
	}

	return 1;
}

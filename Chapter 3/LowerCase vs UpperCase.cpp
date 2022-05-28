#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;


int main() {

	//we store the string here
	char string[256];
	cout << "Enter your string: ";
	cin >> string;

	//we storing the size of the array
	int size = strlen(string);

	//storing the count of uppercase and lowercase characters
	int lowerCount = 0;
	int upperCount = 0;

	//we loop throught the string
	for (int i = 0; i < size; ++i) {

		//if the current character is between a-z, increase lowerCount
		if (string[i] >= 'a' && string[i] <= 'z') {
			lowerCount++;
		}

		//if the current character is between A-Z, increase upperCount
		if (string[i] >= 'A' && string[i] <= 'Z') {
			upperCount++;
		}

	}

	if (lowerCount > upperCount) {

		cout << "Making all uppercase characters lowercase: ";

		//we make all character lowercase and we print the string
		for (int i = 0; i < size; ++i) {
			string[i] = tolower(string[i]);
			cout << string[i] << ", ";
		}
	}
	else {
		cout << "Making all lowercase characters uppercase: ";

		//we make all the character uppercase and we print the string
		for (int i = 0; i < size; ++i) {
			string[i] = toupper(string[i]);
			cout << string[i] << ", ";
		}
	}

	return 0;
}

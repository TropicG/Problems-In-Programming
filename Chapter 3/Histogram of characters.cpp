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

	//if the string has differenetn symbol than a-z and A-Z it trhows error
	for (int i = 0; i < size; ++i) {
		if (!(string[i] >= 'a' && string[i] <= 'z') && !(string[i] >= 'A' && string[i] <= 'Z')) {
			cout << "In your string there is invalid character";
			return -1;
		}
	}

	//here we will store the table with all the symbols
	char characters[27];

	//helper index to help us type the table with characters
	int j = 65;

	//here we will store all the numbers for the corresponding character count
	int count[26];

	//making all the character in uppercase because it will be easier for us
	for (int i = 0; i < size; i++) {
		string[i] = toupper(string[i]);
	}

	//initializng the count table
	for (int i = 0; i < 26; i++) {
		count[i] = 0;
	}

	//initializng the character table
	for (int i = 0; i < 26; i++) {
		characters[i] = (char)j;
		j++;
	}

	//goes throught the whole string, and checks and increase count on the given character
	for (int i = 0; i < size; i++) {
		if (string[i] == 'A') {
			count[0]++;
		}
		else if (string[i] == 'B') {
			count[1]++;
		}
		else if (string[i] == 'C') {
			count[2]++;
		}
		else if (string[i] == 'D') {
			count[3]++;
		}
		else if (string[i] == 'E') {
			count[4]++;
		}
		else if (string[i] == 'F') {
			count[5]++;
		}
		else if (string[i] == 'G') {
			count[6]++;
		}
		else if (string[i] == 'H') {
			count[7]++;
		}
		else if (string[i] == 'I') {
			count[8]++;
		}
		else if (string[i] == 'J') {
			count[9]++;
		}
		else if (string[i] == 'K') {
			count[10]++;
		}
		else if (string[i] == 'L') {
			count[11]++;
		}
		else if (string[i] == 'M') {
			count[12]++;
		}
		else if (string[i] == 'N') {
			count[13]++;
		}
		else if (string[i] == 'O') {
			count[14]++;
		}
		else if (string[i] == 'P') {
			count[15]++;
		}
		else if (string[i] == 'Q') {
			count[16]++;
		}
		else if (string[i] == 'R') {
			count[17]++;
		}
		else if (string[i] == 'S') {
			count[18]++;
		}
		else if (string[i] == 'T') {
			count[19]++;
		}
		else if (string[i] == 'U') {
			count[20]++;
		}
		else if (string[i] == 'V') {
			count[21]++;
		}
		else if (string[i] == 'W') {
			count[22]++;
		}
		else if (string[i] == 'X') {
			count[23]++;
		}
		else if (string[i] == 'Y') {
			count[24]++;
		}
		else {
			count[25]++;
		}
	}

	cout << "Displaying the histrogram for the string you entered:" << endl;
	for (int i = 0; i < 26; i++) {
		cout << "The symbol " << characters[i] << " was met " << count[i] << " times." << endl;
	}

	return 0;
}

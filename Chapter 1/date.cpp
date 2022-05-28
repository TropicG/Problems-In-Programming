#include <iostream>
using namespace std;

int main() {

	//storing the user's date birth
	int date = 0;
	cout << "Enter your date of birth: ";
	if (!(cin >> date) || date < 0 || date >31) {
		cout << "Invalid argument!";
		return -1;
	}

	//storing the bits for the binary base
	int Binbits[5];
	for (int i = 0; i < 5; ++i) {
		Binbits[i] = 0;
	}

	//using binary so we cant change the date and indexB represent the index in Binbits
	int binary = date, indexB = 0;
	while (binary != 0) {
		Binbits[indexB] = binary % 2;
		indexB++;
		binary /= 2;
	}

	int Octbits[2];
	for (int i = 0; i < 2; i++) {
		Octbits[i] = 0;
	}

	int octal = date, indexO = 0;
	while (octal != 0) {
		Octbits[indexO] = octal % 8;
		indexO++;
		octal /= 8;
	}

	char Hexbits[3];
	for (int i = 0; i < 3; i++) {
		Hexbits[i] = '\0';
	}

	int hexal = date, indexH = 0;
	while (hexal != 0) {
		if (hexal % 16 == 10) {
			Hexbits[indexH] = 'A';
			indexH++;
			hexal /= 16;
		}
		else if (hexal % 16 == 11) {
			Hexbits[indexH] = 'B';
			indexH++;
			hexal /= 16;
		}
		else if (hexal % 16 == 12) {
			Hexbits[indexH] = 'C';
			indexH++;
			hexal /= 16;
		}
		else if (hexal % 16 == 13) {
			Hexbits[indexH] = 'D';
			indexH++;
			hexal /= 16;
		}
		else if (hexal % 16 == 14) {
			Hexbits[indexH] = 'E';
			indexH++;
			hexal /= 16;
		}
		else if (hexal % 16 == 15) {
			Hexbits[indexH] = 'F';
			indexH++;
			hexal /= 16;
		}
		else {
			Hexbits[indexH] = '0' + (hexal % 16);
			indexH++;
			hexal /= 16;
		}

	}

	Hexbits[indexH] = '\0';


	cout << "Your birth date represented in binary number system is: ";
	for (int i = indexB-1; i >= 0; --i) {
		cout << Binbits[i];
	}
	cout << endl;

	cout << "Your birth date represented in octal number system is: ";
	for (int i = indexO-1; i >= 0; --i) {
		cout << Octbits[i];
	}
	cout << endl;

	cout << "Your birth date represented in hexademical number system is: ";
	for (int i = indexH-1; i >= 0; --i) {
		cout << Hexbits[i];
	}
	cout << endl;


	return 0;
}

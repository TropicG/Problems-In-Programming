#include <iostream>
using namespace std;

bool inside(int number, int digit) {

	if (number < 10 && number != digit) {
		return false;
	}

	if (number < 10 && number == digit) {
		return true;
	}

	if (number % 10 == digit) {
		return true;
	}

	return inside(number / 10, digit);
}

int main() {


	int number = 0, digit = 0;
	cout << "Enter the number: ";
	if (!(cin >> number) || number <=0 ) {
		cout << "Invalid argument!";
		return -1;
	}

	cout << "Enter the digit: ";
	if (!(cin >> digit) || digit <=0) {
		cout << "Invalid argument!";
		return -2;
	}

	while (digit >= 10) {

		cout << "The digit should be lower than 10, try again: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> digit;

	}

	if (inside(number, digit)) {
		cout << "True";
	}
	else {
		cout << "False";
	}

	return 0;
}

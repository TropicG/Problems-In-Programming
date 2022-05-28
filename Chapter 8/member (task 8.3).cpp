#include <iostream>
using namespace std;



template<typename T>
void input(T* array, const int& n) {

	for (int i=0; i < n; ++i) {

		cin >> array[i];

		//check in case the array is for integers and the user input character
		while (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid argument, try again: ";
			cin >> array[i];
		}

	}


}


template<typename T>
bool member(const T* array, int n, const T& x) {

	for (int i = 0; i < n; ++i) {
		if (x == array[i]) {
			return true;
		}
	}

	return false;
}



int main() {

	//size of the arrays
	int n = 0;
	cout << "Enter how many elements you want to input: ";

	if (!(cin >> n)) {
		cout << "Invalid argument, try again";
		return -1;
	}

	//array for the numbers
	int* numbers = new int[n];
	if (!numbers) {
		cout << "Failed allocation";
		delete[] numbers;
		return -2;
	}

	//array for the symbols
	char* symbols = new char[n];
	if (!symbols) {
		cout << "Failed allocation";
		delete[] symbols;
		return -3;
	}



	//inputting characters for the numbers
	cout << "Enter all the numbers in the array: ";
	input(numbers, n);

	//inputting symbols for the numbers
	cout << "Enter all the characters in the array: ";
	input(symbols, n);

	//here we store the inputted number and character and check are they in the arrays
	int number = 0;
	char symbol;

	cout << "Enter the number you want to check in the numbers: ";
	cin >> number;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invalid argument, try again: ";
		cin >> number;
	}

	cout << "Enter the symbol you want to check in the symbols: ";
	cin >> symbol;

	if (member(symbols, n, symbol)) {
		cout << "The element is inside" << endl;
	}
	else {
		cout << "The element is not inside" << endl;
	}

	if (member(numbers, n, number)) {
		cout << "The element is inside" << endl;
	}
	else {
		cout << "The element is not inside";
	}

	delete[] numbers;
	delete[] symbols;
	return 0;
}

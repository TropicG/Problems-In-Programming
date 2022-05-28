#include <iostream>
using namespace std;



template<typename T>
void input(T& array, const int& n) {

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
bool ordered(const T& array, const int& n) {

	//if the current symbol is bigger than the next it returns false
	for (int i = 0; i < n-1; ++i) {
		if (array[i] > array[i + 1]) {
			return false;
		}
	}

	return true;

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


	if (ordered(numbers, n)) {
		cout << "The numbers are ordered!" << endl;
	}
	else {
		cout << "The numbers are not ordered!" << endl;
	}

	if (ordered(symbols, n)) {
		cout << "The symbols are ordered!" << endl;
	}
	else {
		cout << "The symbols are not ordered!" << endl;
	}


	delete[] numbers;
	delete[] symbols;
	return 0;
}

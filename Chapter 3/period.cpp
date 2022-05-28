#include <iostream>
using namespace std;

bool inside(int* period, const int& size ,const int& number) {

	for (int i = 0; i < size; ++i) {

		if (period[i] == number) {
			return true;
		}

	}

	return false;
}

int main() {

	//the size of the number array
	int size = 0;
	cout << "Enter the size of your number array: ";
	if (!(cin >> size) || size < 0) {
		cout << "Invalid argument";
		return -1;
	}

	//here we store all the numbers
	int* numbers = new int[size];
	if (!numbers) {
		cout << "Bad allocation";
		delete[] numbers;
		return -2;
	}

	//inputting the numbers
	cout << "Input your numbers: ";
	for (int i = 0; i < size; ++i) {

		cin >> numbers[i];
		while (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Bad input, try again: ";
			cin >> numbers[i];
		}

	}

	//here we store the period of the array
	int* period = new int[size];
	if (!period) {
		cout << "Bad allocation";
		delete[] period;
		return -3;
	}

	//size of the period array
	int index = 0;

	//determing the period
	for (int i = 0; i < size; ++i) {

		//if the current element of numbers is inside the period we end the cycle
		if (inside(period, index, numbers[i])) {
			break;
		}

		//else we input the number to the period
		period[index] = numbers[i];
		index++;
	}

	//we go through all the numbers array to see is there period
	for (int i = 0; i < size - index; ++i) {


		//index that will help us to compare the next elements from position i
		int n = i;


		//checks to next j elements are they not equal to not be period
		for (int j = 0; j < index; ++j) {

			if (numbers[n] != period[j]) {
				cout << "There is no period";
				delete[] numbers;
				delete[] period;
				return 0;
			}

			n++;
		}

	}

	cout << "There is period";
	delete[] numbers;
	delete[] period;
	return 0;
}

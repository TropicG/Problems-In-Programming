#include <iostream>
using namespace std;

int getSumDivisors(int num) {

	int sum = 0;

	for (int i = 1; i < num; ++i) {
		if (num % i == 0) {
			sum += i;
		}
	}

	return sum;

}

int main() {

	int num = 0;
	cout << "Enter the number: ";
	if (!(cin >> num) || num < 0) {
		cout << "Invalid argument!";
		return -1;
	}

	int* numbers = new int[num/2];
	if (numbers == nullptr) {
		cout << "Bad allocation";
		delete[] numbers;
		return -2;
	}

	int index = 0;

	for (int i = 1; i < num; ++i) {

		if (getSumDivisors(i) == i) {
			numbers[index] = i;
			index++;
		}

	}


	cout << "All the special numbers in the range [1," << num << "] are: ";
	for (int i = 0; i < index; ++i) {
		cout << *(numbers + i) << " ";
	}

	delete[] numbers;
	return 0;
}

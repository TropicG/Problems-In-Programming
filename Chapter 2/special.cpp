#include <iostream>
using namespace std;

bool special(int& number) {

	int sum = 0;
	while (number != 0) {
		sum += number % 10;
		number /= 10;
	}

	if (sum % 3 == 0) {
		return true;
	}
	else {
		return false;
	}

}

int main() {

	int number = 0;
	cout << "Enter the number: ";
	if (!(cin >> number) || number < 0) {
		cout << "Invalid argument";
		return -1;
	}


	if (special(number)) {
		cout << "Yes, the sum of the digit can be divided by 3";
		return 0;
	}
	else {
		cout << "No, the sum of the digits cant be divided by 3";
		return 0;
	}
}

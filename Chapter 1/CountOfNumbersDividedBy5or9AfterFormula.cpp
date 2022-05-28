#include <iostream>
using namespace std;

int main() {

	int n = 0;
	cout << "Enter value for n: ";

	if (!(cin >> n)) {
		cout << "Invalid argument";
		return -1;
	}

	if (n < 1) {
		cout << "n cant be lower than 1";
		return -2;
	}

	//here we store the count
	int count = 0;
	for (int i = 1; i <= n; i++) {

		//if num is divided by 5 or 9 after this formula we increase the count
		int number = (i * i * i) + (13 * i * n) + (n * n * n);
		if (number % 5 == 0 || number % 9 == 0) {
			count++;
		}

	}

	cout << "The count of the numbers is: ";
	cout << count;
	return 0;

}

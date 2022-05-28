#include <iostream>
using namespace std;

int mult(int m, int n) {

	if (n == 1) {
		return m;
	}

	return m + mult(m, n - 1);


}

int main() {

	int m = 0, n = 0;

	cout << "Enter the first number: ";
	if (!(cin >> m)) {
		cout << "Invalid argument!";
		return -1;
	}

	cout << "Enter the second number: ";
	if (!(cin >> n)) {
		cout << "Invalid argument!";
		return -2;
	}


	cout << "The production of these number is: " << mult(m, n);




	return 0;
}

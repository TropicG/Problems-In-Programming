#include <iostream>
using namespace std;

double ermit(int n, int x) {

	if (n == 0) {
		return 1.0;
	}

	if (n == 1) {
		return 2.0 * x;
	}

	return 2.0 * x * ermit(n - 1, x) + 2.0 * (n - 1) * ermit(n - 2, x);

}

int main() {

	int x = 0;
	cout << "Enter your number: ";
	if (!(cin >> x)) {
		cout << "Invalid argument, try again!";
		return -1;
	}

	int n = 0;
	cout << "Enter on which stage you want to see your number: ";
	if (!(cin >> n)) {
		cout << "Invalid argument, try again!";
		return -2;
	}

	cout << "The value of ermit is: " << ermit(n, x);

	return 0;
}

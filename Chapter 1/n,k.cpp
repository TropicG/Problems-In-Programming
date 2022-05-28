#include <iostream>
using namespace std;

int main() {


	int n = 0, k = 0;
	cout << "Enter the n: ";
	if (!(cin >> n) || n < 0) {
		cout << "Invalid argument";
		return 0;
	}

	cout << "Enter the k: ";
	if (!(cin >> k) || k < 0) {
		cout << "Invalid argument";
		return 0;
	}

	int power = 0;
	while (true) {

		if (k ^ power > n) {
			cout << "False";
			return 0;
		}

		if (k ^ power == n) {
			cout << "True";
			return 0;
		}

		power++;

	}
}

#include <iostream>
using namespace std;

int main() {

	int size = 0;
	cout << "Enter the size of the two arrays: ";
	if (!(cin >> size) || size < 1 || size > 50) {
		cout << "Invalid argument";
		return -1;
	}

	int* a = new int[size];
	if (!a) {
		cout << "Bad memory allocation";
		return -2;
	}

	int* b = new int[size];
	if (!b) {
		cout << "Bad memory allocation";
		return -3;
	}

	cout << "Input the first array: ";
	for (int i = 0; i < size; ++i) {
		cin >> a[i];
	}

	cout << "Input the second array: ";
	for (int i = 0; i < size; ++i) {
		cin >> b[i];
	}

	int sets = 0;

	for (int i = 0; i < size-3; ++i) {

		for (int j = 0; j < size - 3; ++j) {

			if (a[i] == b[j] && a[i + 1] == b[j + 1] && a[i + 2] == b[j + 2]) {
				sets++;
			}

		}

	}


	if (sets >= 2) {
		cout << "True";
	}
	else {
		cout << "False";
	}

	delete[] a;
	delete[] b;
	return 0;
}

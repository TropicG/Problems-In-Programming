#include <iostream>
using namespace std;

template<typename T>
void swaparrays(T* a, T* b, int sizea, int sizeb) {

	//helper array
	T* helper = new int[sizea];

	//swapping the values of b to helper
	for (int i = 0; i < sizeb; ++i) {
		helper[i] = b[i];
	}

	//swapping the values of a to b
	for (int i = 0; i < sizea; ++i) {
		b[i] = a[i];
	}

	//helper the values of b to a
	for (int i = 0; i < sizea; ++i) {
		a[i] = helper[i];
	}

	delete[] helper;
}

int main() {

	//storing the sizes for array a and array b
	int sizea = 0, sizeb = 0;
	cout << "Enter the number of elements for the first array: ";
	if (!(cin >> sizea)) {
		cout << "Invalid argument";
		return -1;
	}

	cout << "Enter the number of elements for the second array: ";
	if (!(cin >> sizeb)) {
		cout << "Invalid argument";
		return -2;
	}

	//arrays
	int* a = new int[sizea];
	int* b = new int[sizeb];

	//inputting array a
	for (int i = 0; i < sizea; ++i) {
		cin >> a[i];

		while (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid argument, try again: ";
			cin >> a[i];
		}

	}

	//inpputing array b
	for (int i = 0; i < sizeb; ++i) {
		cin >> b[i];

		while (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid argument, try again: ";
			cin >> b[i];
		}

	}

	//swapping the arrays
	swaparrays(a, b, sizea, sizeb);
	return 0;
}

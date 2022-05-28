#include <iostream>
using namespace std;

bool duplicates(long* pointers[], const int& i, const int& j) {

	//checking for dublicates
	for (int n = 0; n < i; ++n) {
		for (int m = 1; m < j; ++m) {

			//if any of the rest elements in a given subarray is equal to the first element
			// in subarray we return true
			if (pointers[n][0] == pointers[n][m]) {
				return true;
			}

		}
	}


	return false;
}

int main() {

	//numbers of subarrays in the array, number of elements in the subarray
	int i = 0, j = 0;

	cout << "Enter the numbers of arrays you want in your array: ";
	if (!(cin >> i)) {
		cout << "Invalid argument!";
		return -1;
	}

	cout << "Enter the numbers of element in each array: ";
	if (!(cin >> j)) {
		cout << "Invalid argument!";
		return -2;
	}

	long** pointers = new long*[i];

	//memory allocation check
	if (!pointers) {
		cout << "Unsuccsesfull memory allocation!";
		delete[] pointers;
		return -3;
	}

	//allocationg memory
	for (int k = 0; k < i; ++k) {

		pointers[k] = new long[j];

		//memory allocation check
		if (!pointers[k]) {

			for (int n = 0; n < i; ++i) {
				delete[] pointers[n];
			}

			delete[] pointers;
			cout << "Unsuccsessfull memory allocation!";
			return -4;
		}

	}

	//inputting the array
	for (int n = 0; n < i; ++n) {
		for (int m = 0; m < j; ++m) {

			cin >> pointers[n][m];
			while (cin.fail()) {
				cin.clear();
				cin.ignore(256,'\n');
				cout << "Invalid argument, try again: ";
				cin >> pointers[n][m];
			}
		}
	}

	if (duplicates(pointers, i, j)) {
		cout << "True";
	}
	else {
		cout << "False";
	}

	for (int n = 0; n < i; ++n) {
		delete[] pointers[n];
	}
	delete[] pointers;
	return 0;
}

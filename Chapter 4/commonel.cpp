#include <iostream>
using namespace std;

bool commonel(int** arrays, const int& npointers,int* arrlenghts) {

	//we check for every element from the first subarray
	for (int currentIndex = 0; currentIndex < arrlenghts[0]; ++currentIndex) {

		//helper bool variable
		bool inside = true;

		//for each subarray we check each of its elements is it equal to the element
		//with the index currentIndiex
		for (int i = 1; i < npointers; ++i) {

			//if we are at the end of the current subarray and we didnt find equal to the
			//element with currentIndex we make inside false
			for (int j = 0; j < arrlenghts[i]; ++j) {
				if (arrays[0][currentIndex] != arrays[i][j] && arrlenghts[i] - j == 1) {
					inside = false;
					break;
				}
			}


		}

		//if we searched every subarray with every element from the first subarray
		//we return false
		if (inside == false && arrlenghts[0]-currentIndex==1) {
			return false;
		}

		//if we found the element with index currentIndex in every subarray we return true
		if (inside) {
			return true;
		}

	}


}

int main() {

	//numbers of pointers in the array
	int npointers = 0;
	cout << "Enter how many pointers do you want to have: ";
	if (!(cin >> npointers)) {
		cout << "Invalid argument";
		return -1;
	}

	//size of every subarray in arrays
	//each size of the subarrays is different
	int* arrlengths = new int[npointers];

	//memory allocations check
	if (!arrlengths) {
		cout << "Invalid memory allocation!";
		delete[] arrlengths;
		return -2;
	}

	//inputting every lenght of subarray in the array
	cout << "Enter the number of element the pointer is linked to: ";
	for (int i = 0; i < npointers; ++i) {
		cin >> arrlengths[i];
		while (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid argument, try again";
			cin >> arrlengths[i];
		}
	}

	//memory allocation for arrays
	int** arrays = new int*[npointers];
	if (!arrays) {
		cout << "Invalid memory allocation!";
		return -3;
	}

	for (int i = 0; i < npointers; ++i) {
		arrays[i] = new int[arrlengths[i]];

		if (!arrays[i]) {
			cout << "Invalid memory allocation!";
			for (int n = 0; n < npointers; ++n) {
				delete[] arrays[i];
			}
			delete[] arrays;
			return -4;
		}

	}

	//inputting everything in arrays
	for (int i = 0; i < npointers; ++i) {
		for (int j = 0; j < arrlengths[i]; ++j) {

			cin >> arrays[i][j];
			while (cin.fail()) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Invalid input, try again: ";
				cin >> arrays[i][j];
			}

		}
	}

	if (commonel(arrays, npointers, arrlengths)) {
		cout << "True";
	}
	else {
		cout << "False";
	}


	return 0;
}

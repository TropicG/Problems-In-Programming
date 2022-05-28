#include <iostream>
using namespace std;

bool swappable(int* arr, const int& size) {

	//index that indicates the end of the first subarray that is sorted
	int sortIndex = 0;

	//gets the index of the first ending of sorted array
	for (int i = 0; i < size - 1; ++i) {

		if (arr[i] > arr[i + 1]) {
			sortIndex++;
			break;
		}

		sortIndex++;
	}

	//checks from that index is the remaining array sorted
	for (int i = sortIndex; i < size - 1; ++i) {

		if (arr[i] > arr[i + 1]) {
			return false;
		}

	}

	//if the first element is bigger than the last element we return true
	if (arr[0] > arr[size - 1]) {
		return true;
	}
	else {
		return false;
	}

}

bool sorted(int* arr, const int& size) {

	for (int i = 0; i < size-1; ++i) {
		if (arr[i] >= arr[i + 1]) {
			return false;
		}
	}

	return true;
}

int main() {

	//size of the array
	int size = 0;
	cout << "Enter the size of the array: ";
	if (!(cin >> size) || size < 0) {
		cout << "Invalid argument";
		return -1;
	}

	//the array
	int* arr = new int[size];
	if (!arr) {
		cout << "Bad memory allocation";
		delete[] arr;
		return -2;
	}

	//inputting the array
	cout << "Input your array: ";
	for (int i = 0; i < size; ++i) {
		cin >> arr[i];
		while (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid argument, try again!";
			cin >> arr[i];
		}
	}

	//checks if the inputted array is already sorted
	if (sorted(arr, size)) {
		cout << "Your array is already sorted!";
		return 1;
	}

	//checks if two parts can swap each other to become sorted array
	if (swappable(arr, size)) {
		cout << "Yes, two parts can swap each other";
		return 2;
	}
	else {
		cout << "No, two parts cant swap each other";
		return 3;
	}

}

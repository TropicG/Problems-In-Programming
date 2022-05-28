#include <iostream>
using namespace std;

int unsortedness(int* arr, const int& size) {

	//count for the elements in bad position
	int count = 0;

	for (int i = 0; i < size; ++i) {

		for (int j = i + 1; j < size; ++j) {

			//if the current element is bigger than the next we increment the count
			if (arr[i] > arr[j]) {
				count++;
			}

		}


	}

	return count;
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

	//memory allocation check
	if (!arr) {
		cout << "Bad allocation";
		delete[] arr;
		return -2;
	}


	//inputting the array
	cout << "Enter your array: ";
	for (int i = 0; i < size; ++i) {
		cin >> arr[i];
		while (cin.fail()) {
			cout << "Invalid argument, try again";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> arr[i];
		}
	}

	cout << "The number of elements in bad position are: " << unsortedness(arr, size);

	delete[] arr;
	return 0;

}

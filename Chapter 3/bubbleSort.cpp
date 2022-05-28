#include <iostream>
using namespace std;


int main() {

	//size of the array
	int size = 0;
	cout << "Enter size of the array: ";
	if (!(cin >> size) || size < 0) {
		cout << "Invalid argument";
		return -1;
	}

	//the array
	int* arr = new int[size];

	//memory allocation check
	if (!arr) {
		cout << "Bad memory allocation";
		return -2;
	}

	//inputting the array
	cout << "Input the array: ";
	for (int i = 0; i < size; ++i) {
		cin >> arr[i];
		while (cin.fail()) {
			cout << "Invalid argument, try again: ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> arr[i];

		}
	}

	//var that helps us in swapping two elements
	int temp = 0;

	//sorting the array in ascending order
	for (int i = 0; i < size; ++i) {

		for (int j = i + 1; j < size; ++j) {


			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}

		}
	}


	cout << "Your array after the sort is: ";
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}

	delete[] arr;
	return 0;
}

#include <iostream>
using namespace std;

//finding the max element, one varible for the array, one to keep track of the max element,
//one for keep track for the end of the array and one for the current index
int findmax(int* arr, int max, int n, int index) {

	if (index > n) {
		return max;
	}

	if (max < arr[index]) {
		return findmax(arr, arr[index], n, index + 1);
	}

	return findmax(arr, max, n, index + 1);

}

int main() {

	int n = 0;
	cout << "Enter how many elements your array will have: ";
	if (!(cin >> n)  || n<1) {
		cout << "Invalid argument!";
		return -1;
	}

	int* arr = new int[n];
	if (!arr) {
		cout << "Bad memory allocation";
		delete[] arr;
		return -2;
	}

	cout << "Enter your elements: ";
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		while (cin.fail()) {
			cout << "Invalid input try again: ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> arr[i];
		}
	}
	cout << "The max element in the array is: " << findmax(arr, arr[0], n,1 );







	return 0;
}

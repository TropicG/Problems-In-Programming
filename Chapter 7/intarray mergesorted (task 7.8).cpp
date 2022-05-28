#include <iostream>
#include <cstring>
using namespace std;

struct intarray {

	//members for the struct
	int* arr;
	size_t size;

	//default constructor, used to return sturct var if the memory allocation failed inside append function
	intarray() : arr(nullptr), size(0) {}

	//sorting the array member
	void sort() {

		//helper var to help us with swapping elements
		int helper = 0;

		for (int i = 0; i < this->size; ++i) {
			for (int j = i + 1; j < this->size; ++j) {
				if (this->arr[i] > this->arr[j]) {
					helper = this->arr[i];
					this->arr[i] = this->arr[j];
					this->arr[j] = helper;
				}
			}
		}
	}

};


intarray mergedsorted(intarray a, intarray b) {

	//here we store the merged array sorted
	intarray merged;
	merged.arr = new int[a.size + b.size];

	//if there is failed memory allocation we return empty array
	if (!merged.arr) {
		return merged;
	}

	//inputting the elements from a to merged
	for (int i = 0; i < a.size; ++i) {
		merged.arr[merged.size] = a.arr[i];
		merged.size++;
	}

	//inputting the elements from b to merged
	for (int i = 0; i < b.size; ++i) {
		merged.arr[merged.size] = b.arr[i];
		merged.size++;
	}

	//sorting the merged array
	merged.sort();

	return merged;
}


int main() {

	//storing the first two arrays
	intarray a, b;
	cout << "How many numbers do you want to push into the first array: ";
	if (!(cin >> a.size)) {
		cout << "Invalid argument";
		return -1;
	}

	cout << "How many numbers do you want to push into the second array: ";
	if (!(cin >> b.size)) {
		cout << "Invalid argument";
		return -2;
	}

	//creating the array member of the struct
	a.arr = new int[a.size];
	if (!a.arr) {
		cout << "Failed memory allocation";
		delete[] a.arr;
		return -3;
	}

	//creating the array member of the struct
	b.arr = new int[b.size];
	if (!b.arr) {
		cout << "Failed memory allocation";
		delete[] b.arr;
		return -4;
	}

	//inputting elements for a
	cout << "Enter the elements for the first array: ";
	for (int i = 0; i < a.size; ++i) {
		cin >> a.arr[i];
		while (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid argument, try again";
			cin >> a.arr[i];
		}
	}

	//inputting elements for b
	cout << "Enter the elements for the second array: ";
	for (int i = 0; i < b.size; ++i) {
		cin >> b.arr[i];
		while (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid argument, try again";
			cin >> b.arr[i];
		}
	}

	//sorting the two arrays
	a.sort();
	b.sort();

	//here we store the merged sorteed array
	intarray merged = mergedsorted(a, b);

	//memory allocation check of the returned function
	if (merged.arr == nullptr) {
		cout << "Failed memory allocation";
		return -5;
	}

	//outputting the sorted merged array
	cout << "The merged sorted array of the two: ";
	for (int i = 0; i < merged.size; ++i) {
		cout << merged.arr[i] << " ";
	}

	return 0;
}

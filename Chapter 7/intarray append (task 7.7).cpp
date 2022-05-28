#include <iostream>
#include <cstdio>
using namespace std;


struct intarray{

	//members for the struct
	int* arr;
	size_t size;

	//default constructor, used to return sturct var if the memory allocation failed inside append function
	intarray() : arr(nullptr), size(0) {}

};


intarray append(intarray a, intarray b) {

	//here we store the append function
	intarray appendArray;

	//allocating mememory enough for the a and b elements
	appendArray.arr = new int[a.size + b.size];

	//memory allocation check, returns empty array if the allocation failed
	if (!appendArray.arr) {
		return appendArray;
	}

	//inputting the elements from a
	for (int i = 0; i < a.size; ++i) {
		appendArray.arr[appendArray.size] = a.arr[i];
		appendArray.size++;
	}

	//inputting the elements from b
	for (int i = 0; i < b.size; ++i) {
		appendArray.arr[appendArray.size] = b.arr[i];
		appendArray.size++;
	}

	return appendArray;

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

	//storing the returned struct from the function
	intarray appendedString = append(a, b);

	//check if memory allocation failed inside the function
	if (appendedString.arr == nullptr) {
		cout << "Failed memory allocation";
		return -5;
	}

	//printing the elements of the array
	cout << "Appended array of the two arrays: ";
	for (int i = 0; i < appendedString.size; ++i) {
		cout <<  appendedString.arr[i] << " ";
	}

	return 0;
}

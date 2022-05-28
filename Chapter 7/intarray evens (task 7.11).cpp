#include <iostream>
#include <cstring>
using namespace std;

struct intarray {

	//members for the struct
	int* arr;
	size_t size;

	//default constructor, used to return sturct var if the memory allocation failed inside append function
	intarray() : arr(nullptr), size(0) {}



};




intarray evens(intarray a) {

	//here we store all the elements from a and b without dublicate
	intarray evensArray;

	//allocating enough memory if there are no dublicates
	evensArray.arr = new int[a.size];

	//memory allocation check
	if (evensArray.arr == nullptr) {
		return evensArray;
	}

	//adding all even elements from a to
	for (int i = 0; i < a.size; ++i) {

		if (a.arr[i] % 2 == 0) {
			evensArray.arr[evensArray.size] = a.arr[i];
			evensArray.size++;
		}

	}

	return evensArray;

}



int main() {

	//storing the array
	intarray a;
	cout << "How many numbers do you want to push into the first array: ";
	if (!(cin >> a.size)) {
		cout << "Invalid argument";
		return -1;
	}


	//creating the array member of the struct
	a.arr = new int[a.size];
	if (!a.arr) {
		cout << "Failed memory allocation";
		delete[] a.arr;
		return -3;
	}

	//inputting elements for a
	cout << "Enter the elements for the array: ";
	for (int i = 0; i < a.size; ++i) {
		cin >> a.arr[i];
		while (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid argument, try again";
			cin >> a.arr[i];
		}
	}

	intarray evensArray = evens(a);
	if (evensArray.arr == nullptr) {
		cout << "Failed allocation";
		delete[] evensArray.arr;
		return -5;
	}

	cout << "Printing the united array: ";
	for (int i = 0; i < evensArray.size; ++i) {
		cout << evensArray.arr[i] << " ";
	}


}

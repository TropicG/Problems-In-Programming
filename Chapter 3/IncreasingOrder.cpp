#include <iostream>
using namespace std;


int main() {

	//count of numbers
	int n = 0;
	cout << "Enter the number of numbers you are going to type: ";
	if (!(cin >> n)) {
		cout << "Invalid argument";
		return -1;
	}
	if (n < 1 || n>100) {
		cout << "N should be [1,100]";
		return -2;
	}

	//here we store all the nums
	int* numbers = new int[n];
	if(numbers==nullptr){
        cout << "Bad memory allocation. Exiting program..";
        return -3;
	}

	for (int i = 0; i < n; ++i) {

		cout << "Enter your number: ";

		//if the input gives error
		if (!(cin >> numbers[i])) {

			//loops until the user type valid argument
			while (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered invalid argument, please try again: ";
				cin >> numbers[i];
				if (!cin.fail()) {
					break;
				}
			}
		}

	}

	//storing if the array is increaing
	bool increasing = true;

	for (int i = 0; i < n - 1; ++i) {

		//if the next element is smaller than the previous it makes increasing false and breaks the cycle
		if (numbers[i] > numbers[i + 1]) {
			increasing = false;
			break;
		}
	}

	cout << "Is the array in increasing order: " << increasing;
	return 0;
}

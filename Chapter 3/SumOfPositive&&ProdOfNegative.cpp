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

	//here we store all the nums
	int* numbers = new int[n];
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

	//storing the sum of positive integer
	int sumPlus = 0;

	//storing the production of negative integers
	int prodNegative = 1;


	//goes the whole array
	for (int i = 0; i < n; ++i) {

		//if positive adds to numbers
		if (numbers[i] >= 0) {

			sumPlus += numbers[i];
		}

		//else negative integers multiple
		else {

			prodNegative *= numbers[i];
		}
	}

	cout << "The sum of positive numbers is: " << sumPlus<<endl;
	cout << "The production of negative numbers is: " << prodNegative;

	return 0;
}

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
	if(n < 1 || n > 50){
        cout << "The number should be in [1,50]";
        return -2;
	}

	//here we store all the nums
	int* numbers = new int[n];
	if(numbers==nullptr){
        cout << "Bad memory allocation. Exiting program...";
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

	//takes the first element ot the array as the smallest
	int min = numbers[0];
	for (int i = 1; i < n; ++i) {

		//if some other element is smaller than min, it itself becomes the smallest element
		if (min > numbers[i]) {
			min = numbers[i];
		}
	}

	cout << "The minimal numbers is: " << min;
	return 0;
}

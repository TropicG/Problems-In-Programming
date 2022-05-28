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
        cout << "The num should be in [1,50]";
        return -2;
	}

	//here we store all the nums
	int* numbers = new int[n];
	if(numbers==nullptr){
        cout << "Bad memory allocation. Exiting program.."
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

	//storing the sum of doubled odd numbers
	int sum = 0;
	for (int i = 0; i < n; ++i) {

		//if number is %2 by to and number/2 is not%2 then its added to sum
		if (numbers[i] % 2 == 0 && (numbers[i] / 2) % 2 != 0) {
			sum += numbers[i];
		}

	}

	cout << "The sum of doubled odd numbers is: " << sum;
	return 0;
}

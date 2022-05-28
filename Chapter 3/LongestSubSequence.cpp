#include <iostream>
using namespace std;


int main() {

	int n = 0;
	cout << "Enter how many numbers your sequence will have: ";

	//if n is invalid argument throws error
	if (!(cin >> n)) {
		cout << "Invalid argument! ";
		return -1;
	}

	//throws error if n is not between [1,100]
	if ((n < 1 ) || (100 < n)) {
		cout << "The number of numbers should be between [1,100]";
		return -2;
	}

	//here we will store the numbers
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

	//we have one variable for the max length of decreasing sequence
	//and one for the current to check the length of every decreasing sequence
	int max = 1;
	int current = 1;

	for (int i = 0; i < n-1; ++i) {

		//if the next numbers is < than the previous, the current variable is ++
		if (numbers[i] >= numbers[i + 1]) {
			current++;
		}

		//if the next numbers is not < than the previous,
		else {

			//checks if the current subsequence is longer than the max subsequnce
			//if it is < the current becomes max and current reset itself
			if (max < current) {
				max = current;
				current = 1;
			}

			//else the current is reset
			else {
				current = 1;
			}
		}
	}

	cout << "The longest subsequence is: " << max;
	return 0;
}

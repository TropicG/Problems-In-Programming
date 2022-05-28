#include <iostream>
using namespace std;


int main() {

	//count of coordinates for the vector
	int n = 0;
	cout << "How many coordinates the vectors will have: ";
	if (!(cin >> n)) {
		cout << "Invalid argument";
		return -1;
	}
	if (n < 0) {
		cout << "The coordinates should not be negative size: ";
		return -2;
	}

	//here we store all the nums
	cout << "Enter coordinates for a: ";
	int* a = new int[n];
	if(a==nullptr){
        cout << "Bad memory allocation. Exiting program..."
        return -3;
	}

	for (int i = 0; i < n; ++i) {


		//if the input gives error
		if (!(cin >> a[i])) {

			//loops until the user type valid argument
			while (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered invalid argument, please try again: ";
				cin >> a[i];
				if (!cin.fail()) {
					break;
				}
			}
		}

	}

	cout << endl;


	//here we will store the coordinates for b
	cout << "Enter coordinates for b: ";
	int* b = new int[n];
	if(b==nullptr){
        cout << "Bad memory allocation. Exiting program.."
        return -4;
	}

	for (int i = 0; i < n; ++i) {


		//if the input gives error
		if (!(cin >> b[i])) {

			//loops until the user type valid argument
			while (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered invalid argument, please try again: ";
				cin >> b[i];
				if (!cin.fail()) {
					break;
				}
			}
		}

	}

	//here we will store the scalar production
	int scalarProd = 0;
	for (int i = 0; i < n; ++i) {

		//the standart scalar production is = a1*b1 + a2*b2 + ...... = an*bn
		scalarProd += (a[i] * b[i]);
	}

	cout << "The scalar production of vectors a and b: " << scalarProd;
	return 0;
}

#include <iostream>
using namespace std;

int stepmult(int current, int n, int k, int prod) {

	if (current + k > n) {
		return prod;
	}

	return stepmult(current + k, n, k, prod * current);


}



int main() {

	int n = 0, k = 0;

	cout << "Enter the end of the numbers: ";
	if (!(cin >> n) || n<0) {
		cout << "Invalid argument!";
		return -1;
	}

	cout << "Enter the step number: ";
	if (!(cin >> k) || k <0) {
		cout << "Invalid argument!";
		return -2;
	}

	cout << "The production of those numbers is: " << stepmult(1, n, k, 1);

}

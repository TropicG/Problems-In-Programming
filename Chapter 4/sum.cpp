#include <iostream>
#include <cstdio>
using namespace std;

//global variable for the sum of the numbers
double summ = 0;

double sum(size_t n) {

	//end of recursion if there are no numbers to input we return the sum
	if (n == 0) {
		return summ;
	}

	int num = 0;
	cin >> num;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invalid argument, try again: ";
		cin >> num;
	}

	summ += num;

	return sum(n - 1);

}

int main() {


	cout << sum(2);


	return 0;
}

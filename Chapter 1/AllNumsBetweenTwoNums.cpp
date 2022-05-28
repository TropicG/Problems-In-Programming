#include <iostream>
using namespace std;

int main() {

	//the two numbers
	int x = 0, k = 0;

	//input of the first
	cout << "Enter x: ";
	cin >> x;
	cout << endl;

	//input of the second
	cout << "Enter k: ";
	cin >> k;

	//break if k is < 1
	if (k < 1) {
		cout << "k cant be below 1";
		return -1;
	}
	cout << endl;


	//displays all numbers in [x,x+k]
	for (int i = x + k; i >= x; --i) {
		cout << i << " ";
	}

	return 0;
}

#include <iostream>
using namespace std;

int main() {

	int n = 0;
	cout << "Enter the value for n: ";

	if (!(cin >> n)) {
		cout << "Invalid argument";
		return -2;
	}

	if (n < 2) {
		cout << "N should be higher than 2";
		return -1;
	}

	//here we will store the sum of all third numbers till n
	int sum = 0;

	//adds all the third number till n
	for(int i = 2 ; i<=n; i+=3){
		sum += i;
	}

	cout << "The sum of every third number to n is: ";
	cout << sum;
	return 0;
}

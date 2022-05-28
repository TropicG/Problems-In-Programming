#include <iostream>
using namespace std;

int gcd(int a, int b) {

	if (a == b) {
		return a;
	}
	else if(a>b){
		return gcd(a - b, b);
	}
	else {
		return gcd(a, b - a);
	}

}

int main() {

	int a = 0, b = 0;

	cout << "Enter the first number: ";
	if (!(cin >> a) || a<0) {
		cout << "Invalid argument!";
		return -1;
	}

	cout << "Enter the second number: ";
	if (!(cin >> b) || b <0) {
		cout << "Invalid argument!";
		return -2;
	}



}

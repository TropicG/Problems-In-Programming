#include <iostream>
using namespace std;

//function to get fibonachi number for the given index
int getFibonachi(int num) {

	if (num == 0) {
		return 0;
	}

	if (num == 1) {
		return 1;
	}

	return getFibonachi(num - 1) + getFibonachi(num - 2);

}

//we check if the num is fibonachi number
bool fibonachiNum(int fib, int num) {

	//we compare num with every fib index

	//if the given index is bigger than num, we return false
	if (getFibonachi(fib) > num) {
		return false;
	}

	//if the given index is equal to num we return true
	if (getFibonachi(fib) == num) {
		return true;
	}

	//else we return the function with increased index
	return fibonachiNum(fib + 1, num);

}

int main() {

	int num = 0;

	cout << "Enter your num: ";
	if (!(cin >> num)) {
		cout << "Invalid argument, try again";
		return -1;
	}

	if (fibonachiNum(1, num)) {
		cout << "The number is a fibonachi number";
	}
	else {
		cout << "The number is not a fibonachi number";
	}



	return 0;
}

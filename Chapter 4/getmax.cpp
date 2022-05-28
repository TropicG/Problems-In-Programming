#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;

stack<long> numbers;

//getting the element from the stack with recursive way
long get(stack<long> numbers, long max) {

	if (numbers.empty()) {
		return max;
	}

	long helper = numbers.top();
	numbers.pop();

	if (helper > max) {
		return get(numbers, helper);
	}
	return get(numbers, max);

}

void getmax(long* pmax, size_t n) {

	//if we inputted everything we get the max element and we return the fucntion
	if (n == 0) {
		long max = numbers.top();
		numbers.pop();
		*pmax = get(numbers, max);
		return;
	}


	//inputting
	long num = 0;
	cin >> num;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(256,'\n');
		cout << "Invalid argument, try again: ";
		cin >> num;
	}

	//putting into the stack
	numbers.push(num);
	return getmax(pmax, n - 1);

}

int main() {

	int n = 0;
	cout << "Enter how many numbers you will input: ";
	if (!(cin >> n)) {
		cout << "Invalid argument, try again";
		return -1;
	}

	//the variable that the max element is stored to
	long max = 0;
	getmax(&max, n);
	cout << max;

	return 0;
}

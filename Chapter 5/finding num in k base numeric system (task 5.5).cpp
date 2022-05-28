#include <iostream>
#include <stack>
using namespace std;

//recursive function to get the sum of the digits of the nums
int digitSum(int num, int sum) {

	if (num < 10) {
		return sum + num;
	}

	return digitSum(num/10, sum + num%10);
}

//here we transform the sum of the digits and push them into stack
void getNum(int num, int base, stack<int>& bits) {

	//if we reached the end we return the function
	if (num == 0) {

		return;
	}

	//we add the bit to the stack
	bits.push(num % base);

	//we return the function with num divided by base
	return getNum(num / base, base, bits);

}

//here we print the stack
void printStack(stack<int>& bits) {

	if (bits.empty()) {
		return;
	}

	int helper = bits.top();
	cout << helper;
	bits.pop();

	return printStack(bits);

}

int main() {

	int num = 0, base = 0;
	cout << "Enter your number: ";
	if (!(cin >> num)) {
		cout << "Invalid argument!";
		return -1;
	}

	cout << "Enter the base of the counting system for the sum of the digits: ";
	if (!(cin >> base)) {
		cout << "Invalid argument!";
		return -2;
	}

	stack<int> bits;
	getNum(digitSum(num,0), base, bits);

	cout << "Your number in " << base << " numeric system is: "; printStack(bits);


	return 0;
}

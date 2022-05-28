#include <iostream>
#include <stack>
using namespace std;

//we push and pop the numbers in the stack se we can achieve reverse order
stack<int> numbers;

//printing the numbers from the stack
void print(stack<int> numbers) {

	//if it is empty we return the function
	if (numbers.empty()) {
		return;
	}

	//else we print the element at the top of the stack and we pop it
	cout << numbers.top() << endl;
	numbers.pop();

	return print(numbers);


}

void reverse(int n) {

	//if there are no numbers to input we print the stack
	if (n == 0) {
		cout << "Reverse order: " << endl;
		print(numbers);
	}

	int num = 0;
	cin >> num;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invalid argument, try again: ";
		cin >> num;
	}

	//we push the number in the stack
	numbers.push(num);

	return reverse(n - 1);

}

int main() {

	int n = 0;
	cout << "Enter how many numbers you want to add: ";
	if (!(cin >> n)) {
		cout << "Invalid argument, try again: ";
		return -1;
	}

	cout << "Enter your numbers: ";
	reverse(n);

	return 0;
}

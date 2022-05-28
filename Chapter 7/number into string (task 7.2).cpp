#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

//function to get every digit from the number and put it into the stack
void getDigits(int& number, stack<char>& digits) {

	while (number != 0) {

		//helper variable so we can make a digit from the number to a char symbol
		//for example if the current digit is 5 we do '0' + 5 and we get '5'
		char temp = '0';

		//push the digit to the stack
		digits.push(temp + (number % 10));

		//we divide the number by 10
		number /= 10;

	}

}

//we use stack in order to achieve constant time
char* storeString(stack<char>& digits) {

	//size of stack
	int size = digits.size();

	//allocated memory for all the elemets from the stack
	char* string = new char[size + 1];

	//if the allocation failed we return nullptr
	if (!string) { return nullptr; }

	//take the top element of the stack, put it into the array and we pop the stack
	for (int i = 0; i < size; ++i) {
		char temp = digits.top();
		string[i] = temp;
		digits.pop();
	}

	//adding the null terminated character
	string[size] = '\0';

	return string;


}

int main() {

	//number the user input
	int number = 0;

	cout << "Enter your number: ";
	if (!(cin >> number) || number<0) {
		cout << "Invalid argument!";
		return -1;
	}

	//storing the digits
	stack<char> digits;

	//getting the digits into the stack
	getDigits(number, digits);

	//making a string and having a pointer pointing to its location
	char* pstring = storeString(digits);
	if (pstring == nullptr) {
		cout << "Unssuccsessful memory allocation!";
		return -1;
	}

	//size of the array the pointer is pointing to
	int psize = strlen(pstring);

	//printing the string
	cout << "Your number in string is: ";
	for (int i = 0; i < psize; ++i) {
		cout << pstring[i];
	}

	//deleting the memory pointed by the pointer
	delete[] pstring;
	return 0;
}

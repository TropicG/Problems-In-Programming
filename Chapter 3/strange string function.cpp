#include <iostream>
#include <string>
using namespace std;


int main() {


	string str;
	cout << "Enter your string: ";
	cin >> str;

	//here we store the new string after the function
	string newStr;

	for (int i = 0; i < str.size(); ++i) {

		//if the current element is z we change it to a
		if (str[i] == 'z') {
			newStr.push_back('a');
		}
		else {
			//else we change the current element of str to the next symbol in asci table
			newStr.push_back((char)(str[i] + 1));
		}
	}

	cout << "The new string is: " << newStr;


	return 0;
}

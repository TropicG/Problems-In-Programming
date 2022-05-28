#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

char* reverse(const char* string, const int& size) {

	//creating a new string in which we store the reversed string
	char revstring[256];

	//index helper for revstring
	int j = 0;

	//doing the cycle until we meet the end of string
	for (int i = size - 1; i >= 0; --i) {

		//making the last character of string the first in revstring
		revstring[j] = string[i];

		//we increase the index for revstring at the end of each loop
		j++;
	}


	//returning the reversed string
	return revstring;

}

int main() {

	//we store the string here
	char string[256];
	cout << "Enter your string: ";
	cin >> string;

	//we storing the size of the array
	int size = strlen(string);

	//pointer returned from the reverse function
	char* revstring = reverse(string, size);

	cout << "The reversed string is: ";

	//inputing the reversed string
	for (int i = 0; i < size; i++) {
		cout << revstring[i];
	}

	return 0;
}

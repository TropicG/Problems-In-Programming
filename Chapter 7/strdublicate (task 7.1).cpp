#include <iostream>
#include <cstring>
using namespace std;

char* strdublicate(const char* string) {

	int size = strlen(string);

	//here we allocate memory for the string
	char* newstr = new char[size + 1];

	//initializing the newly allocated string
	for (int i = 0; i < size; ++i) {
		newstr[i] = string[i];
	}

	//putting a null terminated character at the end
	newstr[size] = '\0';

	return newstr;

}

int main() {

	//here we store the original string
	char string[256];
	cout << "Enter your string: ";
	cin >> string;

	//pointer leading to a array declated in a function
	char* newstr = strdublicate(string);
	cout << "The dublicated string is: ";
	int size = strlen(newstr);

	//printing the array
	for (int i = 0; i < size; ++i) {
		cout << newstr[i];
	}


	//here we delete the memory allocated from the function
	delete[] newstr;
	return 0;
}

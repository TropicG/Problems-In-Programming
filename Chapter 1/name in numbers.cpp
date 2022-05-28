#include <iostream>
#include <cstring>
using namespace std;


int main() {


	char name[32];
	cout << "Enter your name: ";
	cin >> name;

	int size = strlen(name);
	cout << "Your name in numbers is: ";
	for (int i = 0; i < size; ++i) {
		cout << name[i] - 87;
	}

	return 0;
}

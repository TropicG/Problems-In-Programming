#include <iostream>
#include <string>
using namespace std;


bool substring(string& s1, string& s2) {

	int size1 = s1.size(), size2 = s2.size();

	for (int i = 0; i < size1-size2; ++i) {
		if (s1.substr(i, size2) == s2) {
			return true;
		}
	}

	return false;
}

int main() {


	string s1, s2;
	cout << "Enter the first string: "; cin >> s1;
	cout << "Enter the second string: "; cin >> s2;

	if (substring(s1, s2)) {
		cout << "Yes, " << s2 << " is a substring of " << s1;
	}
	else {
		cout << "No, its not a substring";
	}

	return 0;
}

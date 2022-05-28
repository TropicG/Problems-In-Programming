#include <iostream>
using namespace std;

int main() {

	short year = 0;
	cout << "Enter your year: ";
	cin >> year;

	bool leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	if (leap) {
		cout << "Your year is leap";
	}
	else {
		cout << "Your year is not leap";
	}

	return 0;
}

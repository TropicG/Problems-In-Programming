#include <iostream>
using namespace std;

bool valid(const int& year, const int& month, const int& days) {

	bool leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

	if ((month == 4 || month == 6 || month == 9 || month == 11) && days == 31) {
		return false;
	}

	if (leap && days > 29) {
		return false;
	}

	if (!leap && days > 28) {
		return false;
	}

	return true;

}

int main() {

	int year = 0, month = 0, days = 0;

	cout << "Enter the year: ";
	if (!(cin >> year) || year < 0) {
		cout << "Invalid argument for year";
		return -1;
	}

	cout << "Enter the month: ";
	if (!(cin >> month) || month < 1 || month > 12) {
		cout << "Invalid argument for month";
		return -1;
	}

	cout << "Enter the days: ";
	if (!(cin >> days) || days < 1 || days > 31) {
		cout << "Invalid argument for days";
		return -1;
	}

	if (valid(year, month, days)) {
		cout << "The year is valid!";
	}
	else {
		cout << "The year is not valid";
	}



	return 0;
}

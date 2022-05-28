#include <iostream>
using namespace std;

int main() {

	//inputting user's years
	int years = 0;
	cout << "Enter your years: ";
	if (!(cin >> years) || years < 0) {
		cout << "Invalid argument";
		return -1;
	}

	//multipling years by 365 and adding all the days from leap years in the user's lifespan
	int days = years*365 + years/4;
	cout << "You have lived " << days << " days" << endl;

	//multipling all the days by 24 and we get the hours
	int hours = days * 24;
	cout << "You have lived " << hours << " days" << endl;

	//multipling all the hours by 60 to get the minutes
	int minutes = hours * 60;
	cout << "You have lived " << minutes << "minutes" << endl;

	//multipling all the minutes by 60 to get all the seconds
	int seconds = minutes * 60;
	cout << "You have lived " << seconds << " seconds" << endl;


	return 0;
}

#include <iostream>
#include <cmath>
using namespace std;


struct Polar {

	double r;

	Polar() : r(0) {}

	Polar(const double& r) : r(r) {}

	Rect toRect() const {

		double x = this->r*cos(0);
		double y = this->r*sin(0);

		Rect temp(x, y);

		return temp;

	}

	void print() const {

		cout << "(0," << this->r << ") ";

	}

};

struct Rect {

	double x, y;

	Rect() : x(0), y(0) {}

	Rect(const double& x, const double& y) : x(x), y(y) {}


	Polar toPolar() const {

		double r = sqrt(this->x * this->x + this->y * this->y);

		Polar temp(r);

		return temp;
	}

	void print() const {
		cout << "(" << x << "," << y << ") ";
	}

};


int main() {


	char command;
	int count = 0;

	cout << "Enter what kind of vector do you want to type and how many times: ";
	cin >> command;
	if (command != 'r' || command != 'p') {
		cout << "Invalid command: ";
		return -1;
	}
	if (!(cin >> count) || count < 0) {
		cout << "Invalid argument";
		return -2;
	}

	if (command == 'r') {

		Rect* coordinates = new Rect[count];
		if (!coordinates) {
			cout << "Unsuccsessful memory allocation";
			delete[] coordinates;
			return -3;
		}

		for (int i = 0; i < count; ++i) {

			int x = 0, y = 0;

			cout << "Enter the x coordinates: ";
			cin >> x;
			while (cin.fail() || x < 0) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Invalid argument, please try again!";
				cin >> x;
			}

			cout << "Enter the y coordinates: ";
			cin >> y;
			while (cin.fail() || y < 0) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Invalid argument, please try again!";
				cin >> y;
			}

			Rect temp(x, y);
			coordinates[i] = temp;
		}

		cout << "Displaying all the coordinates into polar variant: " << endl;
		for (int i = 0; i < count; ++i) {
			coordinates[i].toPolar().print();
		}


	}




	return 0;
}

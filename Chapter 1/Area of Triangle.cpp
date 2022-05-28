#include <iostream>
#include <cmath>
using namespace std;

//checks if the corresponding values can be valid triangle
bool exists(const float& a, const float& b, const float& c) {
	return ((a + b > c) && (a + c > b) && (b + c > a));
}

int main() {

	//here we store the sides of the triangle and the height of the c
	float a, b, c = 0.0;
	float hc = 0.0;
	cout << "Enter all the size of all the sides of the triangle: ";
	cin >> a >> b >> c;
	cout << endl;

	//if the triangle doesnt exists throws error and ends program
	if (!exists(a, b, c)) {
		cout << "Invalid arguments for a,b,c";
		return -1;
	}

	cout << "Enter the height to the side c:";
	cin >> hc;

	//if the height is > c throws error
	if (hc >= c) {
		cout << "The height to the side c cant be higher than c";
		return -1;
	}
	cout << endl;

	//shows the area by the formula (c.hc)/2
	cout << "The area of the triangle using the (c.hc)/2 is: ";
	cout << (hc * c) / 2;
	cout << endl;

	//shows the area by the heron's formula
	int s = (a + b + c) / 2;
	int area = sqrt(s * (s - a) * (s - b) * (s - c));
	cout << "The area of the triangle using the heren's formula is: ";
	cout << area;

	return 0;
}

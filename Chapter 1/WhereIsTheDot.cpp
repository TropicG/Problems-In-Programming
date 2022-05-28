#include <iostream>
using namespace std;

int main() {

	float x = 0, y = 0;
	cout << "Enter the coordinates of your dot: ";
	cin >> x >> y;

	//if the two values are positive it lies in the I region
	if (x > 0 && y > 0) {
		cout << "Your dot lies in the I region";
		return 1;
	}

	//if x<0 and y>0 it lies in the II region
	else if (x < 0 && y > 0) {
		cout << "Your dot lies in the II region";
		return 2;
	}

	//if the both are negative values it lies in the I region
	else if (x < 0 && y < 0) {
		cout << "Your dot lies in the III region";
		return 3;
	}

	//if x>0 and y<0 it lies in the I region
	else if (x > 0 && y < 0) {
		cout << "Your dot lies in the IV region";
		return 4;
	}

	//if x is 0 it lies on the Ox line;
	else if (x == 0 && (y > 0 || y < 0)) {
		cout << "Your dot lies on the Ox line";
		return 5;
	}

	//if y is 0 it lies on the Oy line
	else if (y == 0 && (x > 0 || x < 0)) {
		cout << "Your dot lies on the 0y line";
		return 6;
	}

	//if x=0 and y=0 it lies in the center
	else {
		cout << "Your dot lies in the center";
		return 7;
	}
}

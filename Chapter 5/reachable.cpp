#include <iostream>
using namespace std;

//checks if there is possible route in the down direction
bool Down(int** matrix, const int& rows, int sx, int sy) {

	if (sx + 1 >= rows || matrix[sx + 1][sy] == 1) {
		return false;
	}

	return true;
}


//checks if there is posibble route in the right direction
bool Right(int** matrix, const int& rows, int sx, int sy) {

	if (sy + 1 >= rows || matrix[sx][sy+1] == 1) {
		return false;
	}

	return true;
}

bool reachable(int** matrix, const int& rows ,int sx, int sy, int dx, int dy) {

	//checks if we have met the desired coordiantes
	if (sx == dx && sy == dy) {
		return true;
	}

	//checks if the route is blocked
	if (matrix[sx][sy] == 1) {
		return false;
	}

	//gets true or false either there is possible movement on these directions
	bool down = Down(matrix, rows, sx, sy);
	bool right = Right(matrix, rows, sx, sy);

	//if there is not possible movement to these directions we return false
	if (!down && !right) {
		return false;
	}

	//mark this tile as blocked
	matrix[sx][sy] = 1;

	//goes in the directions
	if (down) return reachable(matrix, rows, sx + 1, sy, dx, dy);
	if (right) return reachable(matrix, rows, sx, sy + 1, dx, dy);
}

int main() {

	//inputs the size of the matrix
	int rows = 0;
	cout << "Enter the number of rows and cols for the matrix: ";
	cin >> rows;
	while (cin.fail() || rows < 0 || rows>50) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invalid argument, try again: ";
		cin >> rows;
	}

	//initializng the matrix
	int** matrix = new int* [rows];
	if (!matrix) {
		cout << "Bad memory allocation";
		for (int i = 0; i < rows; ++i) {
			delete[] matrix[i];
		}
		delete[] matrix;
		return -2;
	}
	for (int i = 0; i < rows; ++i) {
		matrix[i] = new int[rows];
		if (!matrix[i]) {
			cout << "Bad memory allocation";
			for (int i = 0; i < rows; ++i) {
				delete[] matrix[i];
			}
			delete[] matrix;
			return -3;
		}
	}

	//inputting the matrix
	cout << "Input the routes(0) and blocks(1) in your matrix: ";
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < rows; ++j) {
			cin >> matrix[i][j];
			while (cin.fail() || matrix[i][j] < 0 || matrix[i][j]>1) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Invalid argument, the value should be 0 or 1, try again: ";
				cin >> matrix[i][j];
			}
		}
	}


	//gets the coordinates from which the user wants to starts
	int sx = 0, sy = 0;
	cout << "Enter from which coordinates you want to start: ";
	cin >> sx;
	while (cin.fail() || sx < 0 || sx >= rows) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invalid argument, try again: ";
		cin >> sx;
	}
	cin >> sy;
	while (cin.fail() || sy < 0 || sy >= rows) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invalid argument, try again: ";
		cin >> sy;
	}

	//gets the corrdiantes from wich the suer wants to end
	int dx = 0, dy = 0;
	cout << "Enter the destination of the desired tile: ";
	cin >> dx;
	while (cin.fail() || dx < 0 || dx >= rows) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invalid argument, try again: ";
		cin >> dx;
	}
	cin >> dy;
	while (cin.fail() || dy < 0 || dy >= rows) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invalid argument, try again: ";
		cin >> dy;
	}


	//checks for possible route
	if (reachable(matrix, rows, sx, sy, dx, dy)) {
		cout << "There is route!";
	}
	else {
		cout << "There is no route";
	}

	for (int i = 0; i < rows; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}

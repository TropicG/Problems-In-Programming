#include <iostream>

using namespace std;


int main() {

	//here we store the rows and the collums for the matrix
	int rows = 0, cols = 0;

	cout << "Enter the number of rows in your matrix: ";
	if (!(cin >> rows)) {
		cout << "Invalid argument!";
		return -1;
	}
	if (rows < 1 || rows>20) {
		cout << "The value for rows should be in [1,20]";
		return -2;
	}

	cout << "Enter the number of collums in your matrix: ";
	if (!(cin >> cols)) {
		cout << "Invalid argument!";
		return -1;
	}
	if (cols < 1 || cols>30) {
		cout << "The value for cols should be in [1,30]";
		return -2;
	}

	//here we store the whole matrix
	int** matrix = new int* [rows];

	//memory allocation check
	if (matrix == nullptr) {
		cout << "Bad memory allocation!";
		for (int i = 0; i < rows; ++i) {
			delete[] matrix[i];
		}
		delete[] matrix;
		return -3;
	}

	//memory allocation
	for (int i = 0; i < rows; i++) {

		matrix[i] = new int[cols];

		if (matrix[i] == nullptr) {

			cout << "Bad memory allocation!";
			for (int i = 0; i < rows; ++i) {
				delete[] matrix[i];
			}
			delete[] matrix;
			return -4;

		}
	}

	//inputing of the matrix
	cout << "Enter your matrix: ";
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cin >> matrix[i][j];
		}
	}

	//here we store all the saddle points
	int saddle[10];

	//here we store the count of saddle points
	int count = 0;

	for (int i = 0; i < rows; ++i) {

		int* smallest = &matrix[i][0];
		int* largest = &matrix[i][0];

		for (int j = 0; j < cols; ++j) {
			if (matrix[i][j] = *smallest) {
				*smallest = matrix[i][j];
			}
		}
		for (int k = 0; k < rows ; ++k) {
			if (matrix[k][i] = *largest) {
				*largest = matrix[k][i];
			}
		}

		if (smallest == largest) {
			saddle[count] = *largest;
			count++;
		}
	}

	cout << "There are " << count << " seddle points in the matrix which are: ";
	for (int i = 0; i < count; i++) {
		cout << saddle[i] << ", ";
	}

	return 0;
}

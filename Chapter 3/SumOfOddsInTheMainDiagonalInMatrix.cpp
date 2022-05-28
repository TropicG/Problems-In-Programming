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
	if (rows < 1 || rows>50) {
		cout << "The value for rows should be in [1,50]";
		return -2;
	}

	cout << "Enter the number of collums in your matrix: ";
	if (!(cin >> cols)) {
		cout << "Invalid argument!";
		return -1;
	}
	if (cols < 1 || cols>50) {
		cout << "The value for cols should be in [1,50]";
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

	//here we store the sum
	int sum = 0;

	//helper index to shows is the element of the main diagonal on every row
	int n = 1;

	for (int i = 1; i < rows; ++i) {
		for (int j = 0; j < n; ++j) {
			if (matrix[i][j] % 2 != 0) {
				sum += matrix[i][j];
			}
		}
		n++;
	}

	cout << "The sum of all elements of the matrix under the main diagonal is: " << sum;

	for(int i=0;i<rows;++i){
        delete[] matrix[i];
	}
	delete[] matrix;
	return 1;
}

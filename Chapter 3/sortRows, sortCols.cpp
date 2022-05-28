#include <iostream>
using namespace std;

void sortRows(int** matrix, const int& rows, const int& cols) {

	//goes through each row of the matrix and applies bubble sort on this row
	for (int n = 0; n < rows; ++n) {

		int temp = 0;
		for (int i = 0; i < cols; ++i) {
			for (int j = i + 1; j < cols; ++j) {

				if (matrix[n][i] > matrix[n][j]) {

					temp = matrix[n][i];
					matrix[n][i] = matrix[n][j];
					matrix[n][j] = temp;
				}
			}
		}
	}
}

void sortCols(int** matrix, const int& rows, const int& cols) {


	//goes through each collum and applies bubble sort on the collum
	for (int n = 0; n < cols; ++n) {


		int temp = 0;
		for (int i = 0; i < rows; ++i) {
			for (int j = i; j < rows; ++j) {

				if (matrix[i][n] > matrix[j][n]) {
					temp = matrix[i][n];
					matrix[i][n] = matrix[j][n];
					matrix[j][n] = temp;
				}
			}
		}
	}
}

int main() {


	//number of rows and cols of the matrix
	int rows = 0, cols = 0;
	cout << "Enter the number of rows for your matrix: ";
	if (!(cin >> rows) || rows < 0) {
		cout << "Invalid argument";
		return -1;
	}

	cout << "Enter the number of cols for your matrix: ";
	if (!(cin >> cols) || cols < 0) {
		cout << "Invalid argument";
		return -2;
	}

	//the matrix
	int** matrix = new int* [rows];
	if (!matrix) {
		cout << "Bad memory allocation";
		for (int i = 0; i < rows; ++i) {
			delete[] matrix[i];
		}
		delete[] matrix;
		return -3;
	}
	for (int i = 0; i < rows; ++i) {
		matrix[i] = new int[cols];
		if (!matrix[i]) {
			cout << "Bad memory allocation";
			for (int i = 0; i < rows; ++i) {
				delete[] matrix[i];
			}
			delete[] matrix;
			return -4;
		}
	}

	//inputting the matrix
	cout << "Enter your matrix: ";
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {

			cin >> matrix[i][j];
			while (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "Invalid argument, try again!";
				cin >> matrix[i][j];
			}

		}
	}

	//sorting each row of the matrix and outputting the matrix
	sortRows(matrix, rows, cols);
	cout << "The matrix after the rows are sorted is: " << endl;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {

			cout << matrix[i][j] << " ";

		}
		cout << endl;
	}

	//sorting each collum of the matrix and outputting the matrix
	sortCols(matrix, rows, cols);
	cout << "The matrix after the cols are sorted is: " << endl;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {

			cout << matrix[i][j] << " ";

		}
		cout << endl;
	}


	for (int i = 0; i < rows; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}

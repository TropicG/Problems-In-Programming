#include <iostream>
using namespace std;

bool smallestInRow(int** matrix, int number ,int i, int j) {

	int smallest = matrix[i][0];

	for (int n = 0; n < j; ++n) {

		if (smallest > matrix[i][n]) {
			smallest = matrix[i][n];
		}

	}

	if (smallest == number) {
		return true;
	}
	else {
		return false;
	}

}

bool biggestInCollum(int** matrix, int number, int i, int j) {


	int smallest = matrix[0][j];

	for (int n = 0; n < i; ++n) {

		if (smallest > matrix[n][j]){
			smallest = matrix[n][j];
		}
	}

	if (smallest == number) {
		return true;
	}
	else {
		return false;
	}



}



int main() {

	int rows = 0, collums = 0;

	cout << "Enter the rows for the matrix: ";
	if (!(cin >> rows) || rows < 1 || rows>20) {
		cout << "Invalid argument for rows";
		return -1;
	}

	cout << "Enter the collums for the matrix: ";
	if (!(cin >> collums) || collums < 1 || collums>30) {
		cout << "Invalid argument for collums";
		return -2;
	}

	int** matrix = new int*[rows];
	if (!matrix) {
		cout << "Bad allocation";
		delete[] matrix;
	}

	for (int i = 0; i < rows; ++i) {

		matrix[i] = new int[collums];

		if (!matrix[i]) {

			cout << "Bad memory allocation";
			for (int i = 0; i < rows; ++i) {
				delete[] matrix[i];
			}

			delete[] matrix;
			return -3;

		}

	}


	int* sedles = new int[rows];
	if (!sedles) {
		cout << "Bad allocation";
		return -4;
	}

	int index = 0;
	for (int i = 0; i < rows; ++i) {

		for (int j = 0; j < collums; ++j) {

			if (smallestInRow(matrix, matrix[i][j], i, j) && biggestInCollum(matrix, matrix[i][j], i, j)) {
				sedles[index] = matrix[i][j];
				index++;
			}

		}

	}

	cout << "All the sedlovi elemets are: ";
	for (int i = 0; i < index; ++i) {
		cout << sedles[i] << " ";
	}


	return 0;
}

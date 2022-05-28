#include <iostream>

using namespace std;


int main() {

	//input the size of the sequences
	int n = 0;
	cout << "Enter the size of the two sequences: ";

	if (!(cin >> n)) {
		cout << "Invalid argument!";
		return -1;
	}
	if (n < 1 || n > 50) {
		cout << "The input should be in [1,50]";
		return -2;
	}

	//creating the two sequences
	int* seqa = new int[n];
	int* seqb = new int[n];

	//memory allocation check
	if (seqa == nullptr || seqb == nullptr) {
		cout << "Bad allocation. Exiting program...";
		delete[] seqa;
		delete[] seqb;
		return -3;
	}

	//initalizing the two sequences
	for (int i = 0; i < n; ++i) {
		seqa[i] = 0; seqb[i] = 0;
	}

	//inputing the sequences
	cout << "Input the first sequance: ";
	for (int i = 0; i < n; ++i) {
		cin >> seqa[i];
	}

	cout << "Input the second sequance: ";
	for (int i = 0; i < n; ++i) {
		cin >> seqb[i];
	}

	//count variable for the matches
	int count = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (seqa[i] == seqb[j]) {
				count++;
			}
		}
	}

	cout << "The number of matches is: " << count;

	delete[] seqa;
	delete[] seqb;
	return -1;
}

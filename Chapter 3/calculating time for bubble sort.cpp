#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {


	const int size = 64;
	int arr[64];

	for (int i = 0; i < size; ++i) {
		arr[i] = rand();
	}

	clock_t start = clock();

	int temp = 0;
	for (int i = 0; i < size; ++i) {
		for (int j = i; j < size; ++j) {

			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}

		}
	}

	clock_t end = clock();

	long miliseconds = (double)(end-start) / (CLOCKS_PER_SEC / 1000.0);
	cout << "The time estimated for sorting the array is: " << miliseconds;
	return 0;

}

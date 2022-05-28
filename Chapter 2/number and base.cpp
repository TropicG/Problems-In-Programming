#include <iostream>
using namespace std;


int main() {

	//inputting the number and the base numeric system
	int number = 0, base = 0;
	cout << "Enter the number: ";
	if (!(cin >> number) || number < 0) {
		cout << "Invalid argument for the number";
		return -1;
	}

	cout << "Enter the base: ";
	if (!(cin >> base) || base < 1 || base > 16) {
		cout << "Invalid argument for the base";
		return -2;
	}

	//index of the array  in which we store the bits from the number
	int index = 0;

	//if the base is <= 10 we work only with numbers
	if (base <= 10) {

		//here we store the bits from the num
		int bits[100];

		while (number != 0) {
			bits[index] = number % base;
			index++;
			number /= base;
		}

		cout << "The number " << number << " represented in " << base << " base system is: ";
		for (int i = index - 1; i >= 0; --i) {
			cout << bits[i];
		}
		return 0;

	}
	else{

		//store the bits from the number
		char bits[100];

		while (number != 0) {

			if (number % base == 10) {
				bits[index] = 'A';
				index++;
				number /= base;
			}
			else if (number % base == 11) {
				bits[index] = 'B';
				index++;
				number /= base;
			}
			else if (number % base == 12) {
				bits[index] = 'C';
				index++;
				number /= base;
			}
			else if (number % base == 13) {
				bits[index] = 'D';
				index++;
				number /= base;
			}
			else if (number % base == 14) {
				bits[index] = 'E';
				index++;
				number /= base;
			}
			else if (number % base == 15) {
				bits[index] = 'F';
				index++;
				number /= base;
			}
			else {
				bits[index] = '0' + (number % base);
				index++;
				number /= base;
			}

		}

		cout << "The number represented in " << base << " base system is: ";
		for (int i = index - 1; i >= 0; --i) {
			cout << bits[i];
		}
		return 0;
	}





	return 0;
}

#include <iostream>
#include <cstring>
using namespace std;


char car(const char* x) {
	return *x;
}

char* cdr(char* x) {
	return x+1;
}

char* cons(char x, const char* y) {

	int size = strlen(y);

	char* consString = new char[size + 2];
	for (int i = 0; i < size; ++i) {
		consString[i] = y[i];
	}

	consString[size] = x;
	consString[size+1] = '\0';


	return consString;

}

bool eq(const char* x, const char* y) {
	int sizeX = strlen(x), sizeY = strlen(y);
	if (sizeX != sizeY) {
		return false;
	}

	for (int i = 0; i < sizeX; ++i) {
		if (x[i] != y[i]) {
			return false;
		}
	}

	return true;
}

char* reverse(char* x) {

	int size = strlen(x);

	char* reverseString = new char[size + 1];

	if (!reverseString) {
		return nullptr;
	}

	reverseString[size] = '\0';


	for (int i = size - 1; i >=  0; i--) {
		reverseString[i] = car(x);
		x = cdr(x);
	}

	return reverseString;
}

char* copy(char* x) {


	int size = strlen(x);

	char* copyString = new char[size + 1];
	if (!copyString) {
		return nullptr;
	}

	for (int i = 0; i < size; i++) {
		copyString[i] = car(x);
		x = cdr(x);
	}

	copyString[size] = '\0';

	return copyString;
}

char* car_n(char* x, int n) {

	char* carnString = new char[n + 1];

	if (!carnString) {
		return nullptr;
	}

	for (int i = 0; i < n; ++i) {
		carnString[i] = car(x);
		x = cdr(x);
	}

	carnString[n] = '\0';

	return carnString;
}

char* cdr_n(char* x, int n) {

	int size = strlen(x);

	char* cdrnString = new char[size - n + 1];
	if (!cdrnString) {
		return nullptr;
	}

	for (int i = 0; i < n; ++i) {
		x = cdr(x);
	}

	for (int i = 0; i < size - n; ++i) {
		cdrnString[i] = car(x);
		x = cdr(x);
	}

	cdrnString[size - n] = '\0';

	return cdrnString;

}

int number_of_char(char* x, char ch) {
	int count = 0, size = strlen(x);

	for (int i = 0; i < size; ++i) {
		if (car(x) == ch) {
			count++;
		}
		x = cdr(x);
	}

	return count;
}

int number_of_substr(char* x, char* y) {

	int sizeX = strlen(x), sizeY = strlen(y), count = 0;

	for (int i = 0; i < sizeX; ++i) {

		bool found = true;
		char* copyX = copy(x);
		char* copyY = copy(y);

		for (int j = i; j < sizeY; ++j) {

			if (car(copyX) != car(copyY)) {
				found = false;
				break;
			}

			copyX = cdr(copyX);
			copyY = cdr(copyY);

		}

		if (found) {
			count++;
		}

		x = cdr(x);

	}


	return count;


}

char* delete_substr(char* x, char* y) {

	int sizeX = strlen(x), sizeY = strlen(y);

	char* delete_substrString = new char[sizeX + 1];
	int index = 0;

	for (int i = 0; i < sizeX - sizeY; ++i) {

		bool found = true;
		char* helperX = copy(x);
		char* helperY = copy(y);

		for (int j = 0; j < sizeY; ++j) {

			if (car(helperX) != car(helperY)) {
				found = false;
			}

			helperX = cdr(helperX);
			helperY = cdr(helperY);

		}

		if (found == false) {

			for (int n= index; n < sizeY; ++n) {
				delete_substrString[n] = x[i];
				i++;
				index++;
			}

			i--;

		}
		else {
			i += sizeY;
			i--;
		}

	}

	return delete_substrString;
}


int main() {

	char string[32] = "Objection";
	cout << "We have this string: " << string << endl;
	cout << "The first symbol of this string is: " << car(string) << endl;

	char* cdrString = cdr(string);
	int sizeCDR = strlen(cdrString);
	cout << "With the first symbol the string is: ";
	for (int i = 0; i < sizeCDR; ++i) {
		cout << *(cdrString + i);
	}
	cout << endl;

	char* consString = cons('!', string);
	int sizeCONS = strlen(consString);
	cout << "The string with added ! at the end: ";
	for (int i = 0; i < sizeCONS; ++i) {
		cout << *(consString + i );
	}
	cout << endl;

	char* reverseString = reverse(string);
	int sizeReverse = strlen(reverseString);
	cout << "The reversed version of Objection is: ";
	for (int i = 0; i < sizeReverse; ++i) {
		cout << *(reverseString+i);
	}
	cout << endl;

	char* copyString = copy(string);
	cout << "Doing the copy of the string: ";
	for (int i = 0; i < sizeReverse; ++i) {
		cout << *(copyString + i);
	}
	cout << endl;

	char* carnString = car_n(string, 4);
	cout << "Getting the first 4 symbol of the string: ";
	for (int i = 0; i < 4; ++i) {
		cout << *(carnString + i);
	}
	cout << endl;

	char* cdrnString = cdr_n(string, 4);
	cout << "Getting the other 5 sumbols of the string: ";
	for (int i = 0; i < 5; ++i) {
		cout << *(cdrnString + i);
	}
	cout << endl;

	char helper[4] = {'O', 'b', 'j','e'};
	char* deleteString = delete_substr(string, helper);
	cout << "Deleting the first 4 symbols of the string: ";
	for (int i = 0; i < 4; ++i) {
		cout << *(deleteString + i);
	}
	cout << endl;







}

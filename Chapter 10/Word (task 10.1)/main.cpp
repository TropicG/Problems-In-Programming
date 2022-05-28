#include "Word.h"

using namespace std;


int main() {

	Word fire("Fire"), emblem("Emblem");

	fire += emblem;
	fire.print();

	if ((fire == emblem) == false) {
		cout << "The strings are not the same" << endl;
	}





	return 0;

}

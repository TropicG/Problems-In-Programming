#include <iostream>
#include <cstring>
using namespace std;

struct Product {

	//information about the products
	char description[32];
	int partNum;
	double cost;

	//default constructor
	Product() : description("none"), partNum(0), cost(0) {}

	//constructor with arguments
	Product(const char* description, const int& partNum, const double& cost) {
		strcpy_s(this->description, strlen(description) + 1, description);
		this->partNum = partNum;
		this->cost = cost;
	}

	//print function
	void print() const {
		cout << this->description << " " << this->partNum << " " << this->cost << endl;
	}
};


int main() {

	//creating the first two products
	Product screwDriver("screw driver", 456, 5.50), hammer("hammer", 324, 8.20);

	cout << "Information about the products: " << endl;
	screwDriver.print();
	hammer.print();

	//creating the an array for the products
	Product products[5];

	//the first two elements
	products[0] = screwDriver;
	products[1] = hammer;

	//inputting, initializng and putting to the array the rest 3 products
	cout << "Input the 3 elements: " << endl;
	for (int i = 2; i < 5; ++i) {

		char desc[32];
		int partnum = 0;
		double cost = 0;

		cout << "Enter the description for the " << i+1 << " product: ";
		cin >> desc;

		cout << "Enter the part num for the " << i+1 << " product: ";
		cin >> partnum;
		while (cin.fail() || partnum < 0) {
			cout << "Invalid argument, try again: ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> partnum;
		}

		cout << "Enter the part num for the " << i+1 << " product: ";
		cin >> cost;
		while (cin.fail() || cost < 0) {
			cout << "Invalid argument, try again: ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> cost;
		}

		Product temp(desc, partnum, cost);
		products[i] = temp;

	}

	//printing all the products
	cout << "Showcasing the elements: " << endl;
	for (int i = 0; i < 5; ++i) {
		products[i].print();
	}





	return 0;
}

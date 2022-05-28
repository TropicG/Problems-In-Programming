#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;


//checking wheter the command is valid
bool valid(string& command) {

	//size of the given argument
	int size = command.length();

	//makes all letters of the command uppercase
	for (int i = 0; i < size; i++) {
		command[i] = toupper(command[i]);
	}

	//if the argument is != from all the commands it returns false
	if (command != "SHOW" && command != "MOVE" && command != "END" && command != "INC" && command != "ZERO" && command != "SUM") {
		return false;
	}

	return true;
}

//used for command SHOW
//prints all the registers
void print(const int* registers, const int& size) {
	for (int i = 0; i < size; i++) {
		cout << registers[i] << " ";
	}
	cout << endl;
}

int main() {

	//storing the number of registers
	int size = 0;
	cout << "Hello enter the numbers of the registers: ";

	//if an invalid character is given as an input it throws error
	if (!(cin >> size)) {
		cout << "Invalid argument";
		return -1;
	}

	//if size is <=0 throws error
	if (size <= 0) {
		cout << "The machine cant be with negative size or be empty";
		return -2;
	}

	//storing the registers
	int* registers = new int[size];

	//making all the characters zero
	for (int i = 0; i < size; ++i) {
		registers[i] = 0;
	}

	//allocation check
	if (registers == nullptr) {
		cout << "Bad allocation";
		delete[] registers;
		return -3;
	}

	//the cycle loop until the program is given the command END
	while (true) {

		//enters the command
		cout << "Enter your command: ";
		string command;
		cin >> command;

		//if the command is invalid it loops the cycle until a valid command is given
		while (!valid(command)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You have entered invalid command, please try again: ";
			cin >> command;
			cout << endl;
			if (valid(command)) {
				break;
			}
		}

		//if the command==INC it takes input for integer and increase the value of the given adress
		//it adress-- since i want the user to type the position of the adress without the 0
		if (command == "INC") {
			int adress = 0;
			cin >> adress;
			if (adress > size || adress < 0) {
				cout << "Invalid adress of a memory";
				cin.clear();
				cin.ignore();
				cout << endl;
			}

			adress--;
			registers[adress]++;
		}


		//if command==ZERO it takes integer as input for adress of the registers and make the value of that register 0
		//as INC it decrements the int input so the user dont have to type accurate indexes for the array
		if (command == "ZERO") {
			int adress = 0;
			cin >> adress;
			if (adress > size || adress < 0) {
				cout << "Invalid adress of a memory";
				cin.clear();
				cin.ignore();
				cout << endl;

			}

			adress--;
			registers[adress] = 0;
		}


		//ending the program
		if (command == "END") {
			cout << "Ending program...";
			return 10;
		}

		//prints the registers
		if (command == "SHOW") {
			print(registers, size);
		}

		//moves the value from index from to index to
		if (command == "MOVE") {
			int from = 0, to = 0;
			cin >> from >> to;
			if ((from > size || from < 0) || (to > size || to < 0)) {
				cout << "Invalid adress of a memory";
				cin.clear();
				cin.ignore();
				cout << endl;
			}

			registers[to] = registers[from];
		}

		//gets the sum of all the registers
		if (command == "SUM") {
			int sum = 0;
			for (int i = 0; i < size; ++i) {
				sum += registers[i];
			}
			cout << "The sum is: " << sum;
			cout << endl;
		}

	}

	return 0;
}

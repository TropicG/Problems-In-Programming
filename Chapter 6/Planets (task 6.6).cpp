#include <iostream>
#include <cstring>
using namespace std;



//struct for the variable planet
struct Planet {

	//member variables for the struct
	char name[32];
	double distance=0, diameter=0, mass=0;


	//default constructor
	Planet() : name("none"), distance(0), diameter(0), mass(0) {}


	//constructor with arguments
	Planet(const char* name, const double& distance, const double& diameter, const double& mass) :
		distance(distance), diameter(diameter),mass(mass) {

		strcpy_s(this->name, strlen(name) + 1, name);

	}

	//printing a single planet
	void print() const {

		cout << "The name of the planet: " << this->name << ", its distance from the Sun its: " << this->distance;
		cout << ", its diametar is: " << this->diameter << " and its mass its: " << this->mass << endl;

	}

	//getting the seconds the light neeeds to reach the planet
	double light() const {

		return this->distance / 299792;

	}




};


//printing all the planets
void printPlanets(const Planet* planets, const int& n) {

	for (int i = 0; i < n; ++i) {

		planets[i].print();

	}

}

//getting the planet with the max distance
Planet getMaxDistance(const Planet* planets, const int& n) {

	Planet max = planets[0];
	for (int i = 0; i < n; ++i) {
		if (planets[i].distance > max.distance) {
			max = planets[i];
		}
	}

	return max;
}

int main() {

	//number of planets
	int n = 0;
	cout << "Enter how many planets do you want: ";
	if (!(cin >> n)) {
		cout << "Invalid argument, try again";
		return -1;
	}

	//array in which we store the planets
	Planet* planets = new Planet[n];
	if (!planets) {
		cout << "Unssucssesfull memory allocation";
		return -2;
	}

	cout << "Enter your planets." << endl;
	for (int i = 0; i < n; ++i) {

		char name[32];
		double distance = 0, diameter = 0, mass = 0;

		cout << "Enter the name for the planet: ";
		cin >> name;

		cout << "Enter its distance from the Sun: ";
		cin >> distance;
		while (cin.fail() || distance < 0) {
			cout << "Invalid argument";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> distance;
		}

		cout << "Enter the diameter of the planet: ";
		cin >> diameter;
		while (cin.fail() || diameter < 0) {
			cout << "Invalid argument";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> diameter;
		}


		cout << "Enter the mass of the planet: ";
		cin >>mass;
		while (cin.fail() || mass < 0) {
			cout << "Invalid argument";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> mass;
		}

		Planet temp(name, distance, diameter, mass);
		planets[i] = temp;

		cout << endl;

	}


	cout << "Showing the information of all of your planets: " << endl;
	printPlanets(planets, n);

	cout << "The planet with the biggest diameter is: " << endl;
	getMaxDistance(planets, n).print();


	return 0;
}

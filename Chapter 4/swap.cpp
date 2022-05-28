#include <iostream>
using namespace std;

template<typename T>
void swap(T& a, T& b) {

	T helper = 0;

	helper = b;
	b = a;
	a = helper;


}

int main() {



	return 0;
}

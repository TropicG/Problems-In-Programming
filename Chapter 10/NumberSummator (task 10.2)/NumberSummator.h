#ifndef  NumbersSummator_H
#define NumbersSumator_H


class NumbersSumator {
private:

	//current sum of the numbers
	int summ;

	//times when the summ was changed
	int count;

	//stores all the numbers that changed summ
	int numbers[20];

public:


	//default constructor
	NumbersSumator(const int& sum);

	//gets the current sum
	int sum() const;

	//adds number to the summ
	void add(const int& num);

	//substract number to the summ
	void sub(const int& num);

	//gets the amout of times the summ was changed
	int num() const;

	//gets the avarage of all the numbers that changed summ
	double avarage() const;
};



#endif

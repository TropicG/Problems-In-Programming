#include "NumbersSummator.h"

//initializez summ with the argument and the count is 0
NumbersSumator::NumbersSumator(const int& sum) : count(0)
{
	this->summ = sum;
}

int NumbersSumator::sum() const
{
	return this->summ;
}

void NumbersSumator::add(const int& num)
{
	//adds the argument to the summ
	this->summ += num;

	//adds the argument to the array and increment the count
	this->numbers[count] = num;
	this->count++;
}

void NumbersSumator::sub(const int& num)
{

	//substract the argument from the summ
	this->summ -= num;

	//adds the argument to the array and increament the count
	this->numbers[count] = num;
	this->count++;

}

int NumbersSumator::num() const
{
	return this->count;
}

double NumbersSumator::avarage() const
{
	//here we store the sum of the all elements in numbers
	double avr = 0;
	for (int i = 0; i < count; ++i) {
		avr += numbers[i];
	}

	//returns the avr/count so we can find the avarage of the all numbers that changed the sum
	return avr / count;
}

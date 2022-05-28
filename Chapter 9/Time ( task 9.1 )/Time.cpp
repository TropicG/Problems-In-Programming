#include "Time.h"


//sets the time, not included error checking for optimization of the code
Time::Time(const int& hours, const int& minutes)
{
	setHours(hours);
	setMinutes(minutes);
}

//copy asssing operator
Time& Time::operator=(const Time& time)
{
	if (this != &time) {

		this->setHours(time.hours);
		this->setMinutes(time.minutes);

	}

	return *this;
}

//if one time is later in the day than the other we return true
bool Time::operator<(const Time& time)
{
	//first checks the hours of the two times
	if (this->hours > time.hours) {
		return false;
	}
	else if (this->hours < time.hours) {
		return true;
	}


	//if they have equal hours we check their minutes
	else {

		if (this->minutes > time.minutes) {
			return false;
		}
		else if (this->minutes < time.minutes) {
			return true;
		}
		else {
			return false;
		}


	}
}

int Time::fromMidnight() const
{
	return this->minutes + this->hours*60;
}

Time Time::operator+(Time& time)
{

	//we create temporary variable because we have to return copy
	Time temp(this->hours, this->minutes);

	//adds the minutes from time to the temp
	temp.addMins(time.minutes);

	//if the two hours togheter are more than 24
	if (temp.hours + time.hours > 24) {

		//we set time.hours to be the value of 24 - this->hours
		time.hours = 24 - this->hours;

		//adds time.hours to this->hours
		this->hours = 0 + time.hours;

	}


	return temp;
}

Time Time::operator-(Time& time)
{

	//we created a temp variable because we will return a copy
	Time temp(this->hours, this->minutes);

	//check if the temp.minutes - time.minutes will be below 0
	if (temp.minutes - time.minutes < 0) {

		time.minutes -= temp.minutes;
		temp.minutes = 60 - time.minutes;
		temp.hours--;
	}

	//check if the temp.hours - time.hours is below 0
	if (temp.hours - time.hours < 0) {
		time.hours -= temp.hours;
		temp.hours = 24 - time.hours;
	}


	return temp;




}

Time Time::operator*(const int& times)
{
	//store the current value of this to temp
	Time temp = *this;

	//it multiplicates *this by temp for times
	//for example instead of *this*7 I do *this + *this + .... + *this
	for (int i = 0; i < times; ++i) {

		*this = *this + temp;

	}


	return *this;

}

void Time::addMins(int& minutes)
{

	if (minutes > 60) {
		throw std::invalid_argument("You have to adds minutes not bigger than 60");
	}

	if (minutes + this->minutes > 60) {

		minutes -= 60 - this->minutes;
		this->minutes = 0 + minutes;
		return;

	}

	this->minutes += minutes;

}

int Time::getHours() const
{
	return this->hours;
}

int Time::getMinutes() const
{
	return this->minutes;
}

void Time::setHours(const int& hours)
{
	if (hours >= 24 || hours < 0) {
		throw std::invalid_argument("Invalid argument!");
	}

	this->hours = hours;
}

void Time::setMinutes(const int& minutes)
{
	if (minutes > 60 || minutes < 0) {
		throw std::invalid_argument("Invalid argument!");
	}
	this->minutes = minutes;
}

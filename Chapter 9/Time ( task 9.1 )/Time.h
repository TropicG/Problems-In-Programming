#ifndef TIME_H
#define TIME_H
#include <stdexcept>


class Time {
private:

	//members of the class
	int hours;
	int minutes;

public:

	//constructor with arguments
	Time(const int& hours, const int& minutes);

	//copy assaingment constructor
	Time& operator=(const Time& time);

	//comparison operator
	bool operator<(const Time& time);

	//gets the minutes from midnight to the current time
	int fromMidnight() const;

	//operators for addition, substraction for dates
	Time operator+(Time& time);
	Time operator-(Time& time);

	//operators for multiplication number by date
	Time operator*(const int& times);

	//adding mins to the time
	void addMins(int& minutes);

	//getting the member hours variable
	int getHours() const;

	//getting the member minutes variable
	int getMinutes() const;

	//setting the hours
	void setHours(const int& hours);

	//setting the minutes
	void setMinutes(const int& minutes);
};



#endif

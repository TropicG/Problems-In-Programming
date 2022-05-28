#include "Point.h"
Point::Point() : x(0), y(0), z(0)
{
}
Point::Point(const double& x, const double& y, const double& z)
{

	this->setX(x);
	this->setY(y);
	this->setZ(z);

}

Point& Point::operator=(const Point& point)
{
	if (this != &point) {


		this->setX(point.getX());
		this->setY(point.getY());
		this->setZ(point.getZ());

	}



	return *this;
}


void Point::setX(const double& x)
{
	this->x = x;
}

void Point::setY(const double& y)
{
	this->y = y;
}

void Point::setZ(const double& z)
{
	this->z = z;
}

double Point::getX() const
{
	return this->x;
}

double Point::getY() const
{
	return this->y;
}

double Point::getZ() const
{
	return this->z;
}

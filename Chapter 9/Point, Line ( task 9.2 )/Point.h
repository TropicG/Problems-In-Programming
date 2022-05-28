#ifndef POINT_H
#define POINT_H


class Point {
private:

	double x, y, z;

public:

	Point();
	Point(const double& x, const double& y, const double& z);
	Point& operator=(const Point& point);



	void setX(const double& x);
	void setY(const double& y);
	void setZ(const double& z);

	double getX() const;
	double getY() const;
	double getZ() const;


};





#endif

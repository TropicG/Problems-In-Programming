#ifndef  LINE_H
#define LINE_H
#include "Point.h"


class Line {
private:

	Point point;
	Point vector;

public:

	Line();
	Line(const Point& point, const Point& vector);



	void setPoint(const Point& point);
	void setVector(const Point& vector);


	Point getPoint();
	Point getVector();


};




#endif

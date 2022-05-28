#include "Line.h"
Line::Line() : point(), vector()
{
}
Line::Line(const Point& point,const Point& vector)
{
    this->setPoint(point);
    this->setVector(vector);
}
void Line::setPoint(const Point& point)
{
    this->point = point;
}
void Line::setVector(const Point& vector)
{
    this->vector = vector;
}
Point Line::getPoint()
{
    return this->point;
}
Point Line::getVector()
{
    return this->vector;
}

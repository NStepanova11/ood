#include "stdafx.h"
#include "Triangle.h"
#include <cmath>

Triangle::Triangle(Point p1, Point p2, Point p3)
	:a(p1)
	,b(p2)
	,c(p3)
	,sideAB(getSide(a, b))
	,sideBC(getSide(b, c))
	,sideCA(getSide(c, a))
{
}

int Triangle::getSide(Point p1, Point p2) {
	return (int) abs(sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2)));
}

int Triangle::getPerimeter() {
	return sideAB + sideBC + sideCA;
}

int Triangle::getArea() {
	return (int)abs(((b.getX() - a.getX())*(c.getY() - a.getY())) - ((c.getX() - a.getX())*(b.getY() - a.getY()))) / 2;
}

void Triangle::draw() {

}
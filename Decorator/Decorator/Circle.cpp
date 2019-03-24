#include "stdafx.h"
#include "Circle.h"


Circle::Circle(Point c, int r)
	:center(c)
	,radius(r)
{
}

int Circle::getPerimeter() {
	return (int)(6.28*radius);
}

int Circle::getArea() {
	return (int)(3.14*pow(radius, 2));
}

void Circle::draw() {
}
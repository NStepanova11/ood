#include "stdafx.h"
#include "Point.h"

Point::Point(int x, int y) 
	:x(x), y(y)
{
}

int Point::getX() {
	return x;
}

int Point::getY() {
	return y;
}
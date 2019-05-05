#include "stdafx.h"
#include "PPoint.h"

PPoint::PPoint(int x, int y)
	:x(x), y(y)
{
}

int PPoint::getX() {
	return x;
}

int PPoint::getY() {
	return y;
}

void PPoint::setX(int x) {
	this->x = x;
}

void PPoint::setY(int y) {
	this->y = y;
}
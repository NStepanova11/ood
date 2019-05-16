#include "CPoint.h"

CCPoint::CCPoint(int x, int y)
	:x(x), y(y)
{
}

int CCPoint::getX() {
	return x;
}

int CCPoint::getY() {
	return y;
}

void CCPoint::setX(int x) {
	this->x = x;
}

void CCPoint::setY(int y) {
	this->y = y;
}
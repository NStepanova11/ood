#include "stdafx.h"
#include "Rectangle.h"

Rectangle::Rectangle(Point leftTop, Point rightBottom)
	:leftTop(leftTop)
	, rightBottom(rightBottom)
	, width(rightBottom.getX() - leftTop.getX())
	, height(rightBottom.getY() - leftTop.getY())
{
}

int Rectangle::getPerimeter(){
	return (width + height) * 2;
}

int Rectangle::getArea(){
	return width*height;
}

void Rectangle::draw() {

}
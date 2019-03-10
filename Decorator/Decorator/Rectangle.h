#pragma once
#include "stdafx.h"
#include "Shape.h"
#include "Point.h"

class Rectangle : public Shape
{
private:
	Point leftTop;
	Point rightBottom;
	int width;
	int height;

public:
	Rectangle(Point leftTop, Point rightBottom);
	int getPerimeter() override;
	int getArea() override;
	void draw() override;
};
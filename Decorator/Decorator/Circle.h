#pragma once
#include "stdafx.h"
#include "Shape.h"
#include "Point.h"
#include <cmath>
#include <SFML\Graphics.hpp>

class Circle : public Shape
{
private:
	Point center;
	int radius;

public:
	Circle(Point c, int r);
	int getPerimeter() override;
	int getArea() override;
	void draw() override;
};
#pragma once
#include "stdafx.h"
#include "Shape.h"
#include "Point.h"

class Triangle : public Shape{
private:
	Point a;
	Point b;
	Point c;
	int sideAB;
	int sideBC;
	int sideCA;

public:
	Triangle(Point p1, Point p2, Point p3);
	int getPerimeter() override;
	int getArea() override;
	void draw() override;
	int getSide(Point p1, Point p2);
};
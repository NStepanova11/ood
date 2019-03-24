#pragma once
#include "stdafx.h"
#include "IShape.h"
#include "Point.h"
#include <cmath>
#include <vector>

using namespace std;


class Triangle : public IShape{
private:
	Point a;
	Point b;
	Point c;
	int sideAB;
	int sideBC;
	int sideCA;

public:
	Triangle(vector<vector<int>> points);
	int getSide(Point p1, Point p2);

	int getPerimeter() override;
	int getArea() override;
	//void draw(RenderWindow &window) override;
};
#pragma once
#include "stdafx.h"
#include "IShape.h"
#include "Point.h"

class Rectangle : public IShape
{
private:
	Point leftTop;
	Point rightBottom;
	int width;
	int height;

public:
	Rectangle(vector<vector<int>> points);

	int getPerimeter() override;
	int getArea() override;
	void draw(RenderWindow &window) override;
};
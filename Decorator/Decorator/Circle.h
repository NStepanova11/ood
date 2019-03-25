#pragma once
#include "stdafx.h"
#include "IShape.h"
#include "Point.h"
#include <cmath>
#include <SFML\Graphics.hpp>

class Circle : public IShape
{
private:
	Point center;
	int radius;

public:
	Circle(vector<vector<int>> points);

	int getPerimeter() override;
	int getArea() override;
	void draw(RenderWindow &window) override;
};
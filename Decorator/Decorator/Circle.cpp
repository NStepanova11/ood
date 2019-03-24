#include "stdafx.h"
#include "Circle.h"


Circle::Circle(vector<vector<int>> points)
	:center(points[0][0], points[0][1])
	,radius(points[1][0])
{
}

int Circle::getPerimeter() {
	return (int)(6.28*radius);
}

int Circle::getArea() {
	return (int)(3.14*pow(radius, 2));
}
/*
void Circle::draw(RenderWindow window) {
	CircleShape circle(radius);
	circle.setFillColor(sf::Color::Red);
	window.draw(circle);
}*/
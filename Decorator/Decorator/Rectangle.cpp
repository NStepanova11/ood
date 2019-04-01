#include "stdafx.h"
#include "Rectangle.h"

Rectangle::Rectangle(vector<vector<int>> points)
	:leftTop(points[0][0], points[0][1])
	, rightBottom(points[1][0], points[1][1])
	, width(rightBottom.getX() - leftTop.getX())
	, height(rightBottom.getY() - leftTop.getY())
{
}

int Rectangle::getPerimeter(){
	return abs((width + height) * 2);
}

int Rectangle::getArea(){
	return width*height;
}

void Rectangle::draw(RenderWindow &window) {
	RectangleShape rectangle(sf::Vector2f(width, height));
	rectangle.setFillColor(sf::Color::Blue);
	rectangle.setPosition(leftTop.getX(), leftTop.getY());
	rectangle.setOutlineThickness(3);
	rectangle.setOutlineColor(Color::White);
	window.draw(rectangle);
}
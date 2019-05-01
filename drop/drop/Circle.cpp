#include "Circle.h"

Circle::Circle(vector<vector<int>> points)
	:top_left(points[0][0], points[0][1])
	,radius(points[1][0])
	,selected(false)
{
}

void Circle::draw(RenderWindow &window) {
	CircleShape circle(radius);
	circle.setFillColor(::Color::Red);
	circle.setPosition(top_left.getX(), top_left.getY());
	if (selected)
		circle.setOutlineThickness(3);
	circle.setOutlineColor(Color::White);
	window.draw(circle);
}

void Circle::select() {
	this->selected = true;
}

void Circle::unSelect() {
	this->selected = false;
}

void Circle::changeFocus() {
	this->selected = !this->selected;
}

bool Circle::isSelected() {
	return this->selected;
}

int Circle::getWidth() {
	return (int)radius * 2;
}

int Circle::getHeight() {
	return (int)radius * 2;
}

bool Circle::isInsideBounds(Vector2i pos) {
	int minX = top_left.getX();
	int minY = top_left.getY();
	int maxX = minX + this->getWidth();
	int maxY = minY + this->getHeight();
	if ((pos.x >= minX && pos.x <= maxX) && (pos.y >= minY && pos.y <= maxY)) {
		return true;
	}
	return false;
}
#include "stdafx.h"
#include "ShapeCircle.h"


ShapeCircle::ShapeCircle(vector<vector<int>> points)
	:top_left(points[0][0], points[0][1])
	, radius(points[1][0])
	, selected(false)
{
}

void ShapeCircle::draw(RenderWindow & window)
{
	CircleShape circle(radius);
	circle.setFillColor(::Color::Red);
	circle.setPosition(top_left.getX(), top_left.getY());
	if (selected)
		circle.setOutlineThickness(3);
	circle.setOutlineColor(Color::White);
	window.draw(circle);
}

int ShapeCircle::getX()
{
	return top_left.getX();
}

int ShapeCircle::getY()
{
	return top_left.getY();
}

int ShapeCircle::getHeight()
{
	return (int)radius * 2;
}

int ShapeCircle::getWidth()
{
	return (int)radius * 2;
}

bool ShapeCircle::isSelected()
{
	return selected;
}

void ShapeCircle::changeFocus()
{
	selected = !selected;
	cout << selected << endl;
}

void ShapeCircle::selectShape()
{
	selected = true;
	cout << "circle in focus" << endl;
}

void ShapeCircle::unselectShape()
{
	selected = false;
	cout << "circle not focus" << endl;

}

bool ShapeCircle::isInsideBounds(Vector2i pos) {
	int minX = top_left.getX();
	int minY = top_left.getY();
	int maxX = minX + getWidth();
	int maxY = minY + getHeight();
	if ((pos.x >= minX && pos.x <= maxX) && (pos.y >= minY && pos.y <= maxY)) {
		return true;
	}
	return false;
}
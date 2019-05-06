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
	shape.setRadius(radius);
	//circle(radius);
	shape.setFillColor(::Color::Red);
	shape.setPosition(top_left.getX(), top_left.getY());
	if (selected)
	{
		shape.setOutlineThickness(3);
		//cout << "circle in focus" << endl;
	}
	else
	{
		//cout << "circle not focus" << endl;
		shape.setOutlineThickness(0);
	}
	shape.setOutlineColor(Color::White);
	window.draw(shape);
}

int ShapeCircle::getX()
{
	//return top_left.getX();
	return shape.getPosition().x;
}

int ShapeCircle::getY()
{
	//return top_left.getY();
	return shape.getPosition().y;
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
	//cout << "circle in focus" << endl;
}

void ShapeCircle::unselectShape()
{
	selected = false;
	//cout << "circle not focus" << endl;
}

bool ShapeCircle::isInsideBounds(Vector2i pos) {
	/*int minX = top_left.getX();
	int minY = top_left.getY();
	int maxX = minX + getWidth();
	int maxY = minY + getHeight();
	if ((pos.x >= minX && pos.x <= maxX) && (pos.y >= minY && pos.y <= maxY)) {
		return true;
	}
	return false;*/
	if (shape.getGlobalBounds().contains(pos.x, pos.y)) {
		return true;
	}
	return false;
}

void ShapeCircle::setX(int x)
{
	top_left.setX(x);
}

void ShapeCircle::setY(int y)
{
	top_left.setY(y);
}

void ShapeCircle::setPosition(Vector2i pos)
{
	shape.setPosition(pos.x, pos.y);
}

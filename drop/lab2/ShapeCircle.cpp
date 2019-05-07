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
	shape.setFillColor(::Color::Red);
	shape.setPosition(top_left.getX(), top_left.getY());
	shape.setOutlineColor(Color::White);
	window.draw(shape);
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

void ShapeCircle::selectShape()
{
	selected = true;
}

void ShapeCircle::unselectShape()
{
	selected = false;
}

bool ShapeCircle::isInsideBounds(Vector2i pos) {
	if (shape.getGlobalBounds().contains(pos.x, pos.y)) {
		return true;
	}
	return false;
}

void ShapeCircle::setPosition(int x, int y)
{
	top_left.setX(x);
	top_left.setY(y);
}

Vector2i ShapeCircle::getPosition()
{
	return Vector2i(shape.getPosition().x, shape.getPosition().y);
}

void ShapeCircle::setDiff(int x, int y)
{
	dx = x;
	dy = y;
}

int ShapeCircle::getDx()
{
	return dx;
}

int ShapeCircle::getDy()
{
	return dy;
}
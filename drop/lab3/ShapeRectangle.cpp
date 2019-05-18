#include "stdafx.h"
#include "ShapeRectangle.h"

ShapeRectangle::ShapeRectangle(vector<vector<int>> points)
	:left_top(points[0][0], points[0][1])
	, right_bottom(points[1][0], points[1][1])
	, width(right_bottom.getX() - left_top.getX())
	, height(right_bottom.getY() - left_top.getY())
	, selected(false)
	, shapeColor(Color::Blue)
	, outLine(0)
{
}

void ShapeRectangle::draw(RenderWindow & window)
{
	shape.setSize(Vector2f(width, height));
	shape.setFillColor(shapeColor);
	shape.setPosition(left_top.getX(), left_top.getY());
	shape.setOutlineThickness(outLine);
	shape.setOutlineColor(Color::White);
	window.draw(shape);
}

int ShapeRectangle::getHeight()
{
	return height;
}

int ShapeRectangle::getWidth()
{
	return width;
}

bool ShapeRectangle::isSelected()
{
	return selected;
}

void ShapeRectangle::selectShape()
{
	selected = true;
}

void ShapeRectangle::unselectShape()
{
	selected = false;
}

bool ShapeRectangle::isInsideBounds(Vector2i pos) {
	if (shape.getGlobalBounds().contains(pos.x, pos.y)) {
		return true;
	}
	return false;
}

void ShapeRectangle::setPosition(int x, int y)
{
	left_top.setX(x);
	left_top.setY(y);
}

Vector2i ShapeRectangle::getPosition()
{
	return Vector2i(shape.getPosition().x, shape.getPosition().y);
}

void ShapeRectangle::setDiff(int x, int y)
{
	dx = x;
	dy = y;
}

int ShapeRectangle::getDx()
{
	return dx;
}

int ShapeRectangle::getDy()
{
	return dy;
}

void ShapeRectangle::setColor(Color shColor)
{
	shapeColor = shColor;
}

void ShapeRectangle::setOutlineSize(int lineSize)
{
	outLine = lineSize;
}

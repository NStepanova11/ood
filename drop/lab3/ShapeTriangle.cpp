#include "stdafx.h"
#include "ShapeTriangle.h"

ShapeTriangle::ShapeTriangle(vector<vector<int>> points)
	:a(points[0][0], points[0][1])
	, b(points[1][0], points[1][1])
	, c(points[2][0], points[2][1])
	, selected(false)
	, moveCoordsX(0)
	, moveCoordsY(0)
	, shapeColor(Color::Yellow)
	, outLine(0)
{
}

void ShapeTriangle::draw(RenderWindow & window)
{
	shape.setPointCount(3);
	shape.setPoint(0, Vector2f(a.getX(), a.getY()));
	shape.setPoint(1, Vector2f(b.getX(), b.getY()));
	shape.setPoint(2, Vector2f(c.getX(), c.getY()));
	shape.setFillColor(shapeColor);
	shape.setPosition(moveCoordsX, moveCoordsY);
	shape.setOutlineThickness(outLine);
	shape.setOutlineColor(Color::White);
	window.draw(shape);
}

int ShapeTriangle::getHeight()
{
	vector<PPoint> points = { a, b, c };
	int min_y = points[0].getY();
	for (auto point : points)
	{
		if (point.getY() < min_y) {
			min_y = point.getY();
		}
	}

	int max_y = points[0].getY();
	for (auto point : points)
	{
		if (point.getY() > max_y) {
			max_y = point.getY();
		}
	}
	return max_y - min_y;
}

int ShapeTriangle::getWidth()
{
	vector<PPoint> points = { a, b, c };
	int min_x = points[0].getX();
	for (auto point : points)
	{
		if (point.getX() < min_x) {
			min_x = point.getX();
		}
	}
	
	int max_x = points[0].getX();
	for (auto point : points)
	{
		if (point.getX() > max_x) {
			max_x = point.getX();
		}
	}
	return max_x - min_x;
}

bool ShapeTriangle::isSelected()
{
	return selected;
}

void ShapeTriangle::selectShape()
{
	selected = true;
}

void ShapeTriangle::unselectShape()
{
	selected = false;
}

bool ShapeTriangle::isInsideBounds(Vector2i pos)
{
	if (shape.getGlobalBounds().contains(pos.x, pos.y)) {
		return true;
	}
	return false;
}

void ShapeTriangle::setPosition(int x, int y)
{
	moveCoordsX = x-minX;
	moveCoordsY = y-minY;
}

Vector2i ShapeTriangle::getPosition()
{
	vector<int> xPoints = { a.getX(), b.getX(), c.getX() };
	vector<int> yPoints = { a.getY(), b.getY(), c.getY() };
	
	minX = xPoints[0];
	minY = yPoints[0];

	for (size_t i = 1; i < xPoints.size(); i++)
	{
		if (xPoints[i] < minX)
			minX = xPoints[i];
		if (yPoints[i] < minY)
			minY = yPoints[i];
	}
	return Vector2i(shape.getPosition().x+minX, shape.getPosition().y+minY);
}
void ShapeTriangle::setDiff(int x, int y)
{
	dx = x;
	dy = y;
}
int ShapeTriangle::getDx()
{
	return dx;
}
int ShapeTriangle::getDy()
{
	return dy;
}

void ShapeTriangle::setColor(Color shColor)
{
	shapeColor = shColor;
}

void ShapeTriangle::setOutlineSize(int lineSize)
{
	outLine = lineSize;
}

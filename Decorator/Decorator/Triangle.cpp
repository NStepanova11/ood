#include "stdafx.h"
#include "Triangle.h"

Triangle::Triangle(vector<vector<int>> points)
	:a(points[0][0], points[0][1])
	,b(points[1][0], points[1][1])
	,c(points[2][0], points[2][1])
	,sideAB(getSide(a, b))
	,sideBC(getSide(b, c))
	,sideCA(getSide(c, a))
{
}

int Triangle::getSide(Point p1, Point p2) {
	return (int) abs(sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2)));
}

int Triangle::getPerimeter() {
	return sideAB + sideBC + sideCA;
}

int Triangle::getArea() {
	return (int)abs(((b.getX() - a.getX())*(c.getY() - a.getY())) - ((c.getX() - a.getX())*(b.getY() - a.getY()))) / 2;
}

void Triangle::draw(RenderWindow &window) {
	ConvexShape convex;
	//double centerX = (a.getX() + b.getX() + c.getX()) / 3;
	//double centerY = (a.getY() + b.getY() + c.getY()) / 3;
	convex.setPointCount(3);
	convex.setPoint(0, Vector2f(a.getX(), a.getY()));
	convex.setPoint(1, Vector2f(b.getX(), b.getY()));
	convex.setPoint(2, Vector2f(c.getX(), c.getY()));
	convex.setFillColor(Color::Yellow);
	convex.setPosition(a.getX(), a.getY());
	convex.setOutlineThickness(3);
	
	convex.setOutlineColor(Color::White);
	window.draw(convex);
}
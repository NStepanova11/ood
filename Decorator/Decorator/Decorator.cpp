#include "stdafx.h"
#include <iostream>
#include "Point.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include <SFML/Graphics.hpp>
#include "FileReader.h"
#include "ShapeDecorator.h"
#include "IShape.h"

using namespace std;

int main()
{
	FileReader freader;
	map<string, vector<vector<int>>> paramsMap = freader.getShapeParams();

	RenderWindow window(VideoMode(800, 600), "SFMLworks");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		
		for (auto element : paramsMap) {
			cout << element.first << endl;
			if (element.first == "TRIANGLE")
			{
				ShapeDecorator shapeDecorator(new Triangle(element.second));
				shapeDecorator.getOperation();
				//shapeDecorator.draw(window);
			}
			/*
			else if (element.first == "RECTANGLE") {
				ShapeDecorator shapeDecorator(new Rectangle(element.second));
				shapeDecorator.getOperation();
				shapeDecorator.draw();
			}
			else if (element.first == "CIRCLE") {
				ShapeDecorator shapeDecorator(new Circle(element.second));
				shapeDecorator.getOperation();
				shapeDecorator.draw();
			}*/
		}
		window.display();
	}
	return 0;
}


/*
for (auto elem : paramsMap) {
cout << elem.first<< ":\n";
for (auto el : elem.second) {
for (auto e: el)
{
cout << e << " ";
}
cout << endl;
}
}*/

/*
Point p3(0, 0);
Circle circle(p3, 100);

sf::RenderWindow window(sf::VideoMode(200, 200), "SFMLworks");
sf::ConvexShape polygon;
polygon.setPointCount(0);
polygon.setPoint(0, sf::Vector2f(p3.getX(), p3.getY()));
polygon.setPoint(1, sf::Vector2f(0, 10));
polygon.setPoint(2, sf::Vector2f(25, 5));
polygon.setOutlineColor(sf::Color::Red);
polygon.setOutlineThickness(5);
polygon.setPosition(10, 20);
polygon.setFillColor(sf::Color::Cyan);

while (window.isOpen())
{
sf::Event event;
while (window.pollEvent(event))
{
if (event.type == sf::Event::Closed)
window.close();
}

window.clear();
window.draw(polygon);
window.display();
}*/

/*

Point p1(0, 0);
Point p2(200, 200);
Point p3(300, 300);
Triangle rectangle(p1, p2, p3);
int p = rectangle.getPerimeter();
cout << p << endl;
return 0;*/
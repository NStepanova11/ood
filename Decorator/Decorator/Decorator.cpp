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

void drawShape(IShape* shape, RenderWindow &window);
void saveShapeParams(list<pair<string, vector<vector<int>>>> &paramsMap);

int main()
{
	FileReader freader;
	list<pair<string, vector<vector<int>>>> paramsMap = freader.getShapeParams();
	saveShapeParams(paramsMap);

	RenderWindow window(VideoMode(800, 600), "Shapes");

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
			if (element.first == "TRIANGLE")
			{
				drawShape(new Triangle(element.second), window);
			}
			else if (element.first == "RECTANGLE") {
				drawShape(new Rectangle(element.second), window);
			}
			else if (element.first == "CIRCLE") {
				drawShape(new Circle(element.second), window);
			}
		}
		window.display();
	}
	return 0;
}


void drawShape(IShape* shape, RenderWindow &window) {
	ShapeDecorator shapeDecorator(shape);
	shapeDecorator.draw(window);
}

void saveShapeParams(list<pair<string, vector<vector<int>>>> &paramsMap) {
	ofstream fout("output.txt");
	for (auto element : paramsMap) {
		if (element.first == "TRIANGLE")
		{
			ShapeDecorator shapeDecorator(new Triangle(element.second));
			fout << element.first << " S=" << shapeDecorator.getArea() << " P=" << shapeDecorator.getPerimeter() << endl;
		}
		else if (element.first == "RECTANGLE") {
			ShapeDecorator shapeDecorator(new Rectangle(element.second));
			fout << element.first << " S=" << shapeDecorator.getArea() << " P=" << shapeDecorator.getPerimeter() << endl;
		}
		else if (element.first == "CIRCLE") {
			ShapeDecorator shapeDecorator(new Circle(element.second));
			fout << element.first << " S=" << shapeDecorator.getArea() << " P=" << shapeDecorator.getPerimeter() << endl;
		}
	}
	fout.close();
}
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
	list<pair<string, vector<vector<int>>>> paramsMap = freader.getShapeParams();

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
				shapeDecorator.draw(window);
			}
			
			else if (element.first == "RECTANGLE") {
				ShapeDecorator shapeDecorator(new Rectangle(element.second));
				shapeDecorator.getOperation();
				shapeDecorator.draw(window);
			}
			else if (element.first == "CIRCLE") {
				ShapeDecorator shapeDecorator(new Circle(element.second));
				shapeDecorator.getOperation();
				shapeDecorator.draw(window);
			}
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

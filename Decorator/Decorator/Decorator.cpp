#include "stdafx.h"
#include <iostream>
#include "Point.h"
#include "Triangle.h"
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFMLworks");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
	/*
	
	Point p1(0, 0);
	Point p2(200, 200);
	Point p3(300, 300);
	Triangle rectangle(p1, p2, p3);
	int p = rectangle.getPerimeter();
	cout << p << endl;
	return 0;*/
}


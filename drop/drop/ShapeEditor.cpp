#include "ShapeEditor.h"
#include <iostream>

using namespace std;

void ShapeEditor::renderWin()
{
	vector <vector<int>> points = { { 0,0 },{ 50 } };
	Circle circle(points);

	RenderWindow window(VideoMode(1000, 700), "SFMLworks");

	while (window.isOpen())
	{
		checkEvent(window, circle);

		window.clear();
		circle.draw(window);
		window.display();
	}
}

void ShapeEditor::checkEvent(RenderWindow &window, Circle &circle) {
	sf::Event event, subEvent;
	while (window.pollEvent(event))
	{
		Vector2i mousePos = Mouse::getPosition(window);

		if (event.type == Event::Closed)
			window.close();
		
		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
			if (circle.isInsideBounds(mousePos)) {
				circle.changeFocus();
				cout << mousePos.x << " " << mousePos.y << endl;
			}
		}
	}
}
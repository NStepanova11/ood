#include "stdafx.h"
#include "ImageEditor.h"

void ImageEditor::renderWin()
{
	RenderWindow window(VideoMode(800, 800), "Panel");

	vector<IShape*> dShapes;
	getShapesFromFile(dShapes);

	CompositeShape composite;

	bool isMove = false;
	float dX = 0;
	float dY = 0;
	Vector2i mousePos = { 0,0 };
	AppPanel panel;

	while (window.isOpen())
	{
		window.setKeyRepeatEnabled(false);
		mousePos = Mouse::getPosition(window);

		checkEvent(window, dShapes, composite, dX, dY, isMove, mousePos, panel);
		window.clear();
		drawShapes(window, dShapes, composite);
		panel.drawPanel(window);
		window.display();
	}
}

void ImageEditor::checkEvent(RenderWindow &window, vector<IShape*> &allShapesVector, CompositeShape &composite,
	float &dX, float &dY, bool &isMove, Vector2i &mousePos, AppPanel &panel)
{
	Event event;
	
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
			for (auto shape : allShapesVector) {
				if (shape->isInsideBounds(mousePos)) {
					if (!shape->isSelected()) {
						composite.add(shape);
					}
					else if (shape->isSelected()) {
						composite.remove(shape);
					}
				}
			}
		}

		if (event.type == Event::MouseButtonPressed && event.key.code == Mouse::Left) {
			if (composite.isInsideBounds(mousePos))
			{
				composite.setDiff(mousePos.x, mousePos.y);
				isMove = true;	
			}
			else if (panel.isInsideBounds(mousePos)) {
				PanelButton * activeButton = panel.getClickedButton(mousePos);
				panel.unselectAllButton();
				activeButton->selectButton();
				AppCommand::perform(activeButton, &composite, &isMove, mousePos, allShapesVector);
			}
		}

		if (event.type == Event::MouseButtonReleased) {
			if (event.key.code == Mouse::Left)
				isMove = false;	
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
			composite.addAll(allShapesVector);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
			composite.removeAll();
		}
	}
	if (isMove) {
		composite.setPosition(mousePos.x, mousePos.y);
	}
}

void ImageEditor::getShapesFromFile(vector<IShape*>& dShapes)
{
	FileReader freader;
	list<pair<string, vector<vector<int>>>> paramsMap = freader.getShapeParams();

	for (auto element : paramsMap) {
		if (element.first == "CIRCLE") {
			IShape* circle = new ShapeCircle(element.second);
			IShape* circleDecorator = new DecoratorShape(circle);
			dShapes.push_back(circleDecorator);
		}
		if (element.first == "RECTANGLE") {
			IShape* rectangle = new ShapeRectangle(element.second);
			IShape* rectangleDecorator = new DecoratorShape(rectangle);
			dShapes.push_back(rectangleDecorator);
		}
		if (element.first == "TRIANGLE") {
			IShape* triangle = new ShapeTriangle(element.second);
			IShape* triangleDecorator = new DecoratorShape(triangle);
			dShapes.push_back(triangleDecorator);
		}
	}
}

void ImageEditor::drawShapes(RenderWindow & window, vector<IShape*> &dShapes, CompositeShape &composite)
{
	for (auto figure : dShapes) {
		figure->draw(window);
	}
	composite.drawFrame(window);
}

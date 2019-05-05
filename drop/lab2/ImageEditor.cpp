#include "stdafx.h"
#include "ImageEditor.h"
#include "FileReader.h"

void ImageEditor::renderWin()
{
	RenderWindow window(VideoMode(1000, 800), "SFMLworks");
	//vector<vector<int>> pp{ { 100,100 },{ 30 } };
	//IShape* circle = new ShapeCircle(pp);
	//IShape* circleDecorator = new DecoratorShape(circle);

	//vector<vector<int>> pp2{ { 200,100 },{ 50 } };
	//IShape* circle2 = new ShapeCircle(pp2);
	//IShape* circleDecorator2 = new DecoratorShape(circle2);
	vector<IShape*> dShapes;
	FileReader freader;
	list<pair<string, vector<vector<int>>>> paramsMap = freader.getShapeParams();
	
	CompositeShape composite;
	for (auto element : paramsMap) {
		if (element.first == "CIRCLE") {
			IShape* circle = new ShapeCircle(element.second);
			IShape* circleDecorator = new DecoratorShape(circle);
			dShapes.push_back(circleDecorator);
			composite.add(circleDecorator);
		}
	}

	
//	composite.add(circleDecorator2);
	//DecoratorShape ds(&circle);

	//dShapes.push_back(circleDecorator);
	//dShapes.push_back(circleDecorator2);

	while (window.isOpen())
	{
		checkEvent(window, dShapes);
		window.clear();
		//circleDecorator->draw(window);
		//dShapes[0]->draw(window);
		composite.draw(window);
		window.display();
	}

}

void ImageEditor::checkEvent(RenderWindow & window, vector<IShape*> &allShapesVector)
{
	Event event;
	Vector2i mousePos = { 0,0 };

	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();

		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
			mousePos = Mouse::getPosition(window);
			for (auto shape : allShapesVector) {
				if (shape->isInsideBounds(mousePos)) {
					shape->changeFocus();
				}
			}
		}
	}

}

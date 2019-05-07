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

	bool isMove = false;//переменная для щелчка мыши по спрайту
	float dX = 0;//корректировка движения по х
	float dY = 0;//по у
	Vector2i mousePos = { 0,0 };

	while (window.isOpen())
	{
		window.setKeyRepeatEnabled(false);
		mousePos = Mouse::getPosition(window);

		checkEvent(window, dShapes, composite, dX, dY, isMove, mousePos);
		window.clear();
		for (auto figure : dShapes) {
			figure->draw(window);
		}
		composite.drawFrame(window);
		window.display();
	}
}

void ImageEditor::checkEvent(RenderWindow &window, vector<IShape*> &allShapesVector, CompositeShape &composite,
	float &dX, float &dY, bool &isMove, Vector2i &mousePos)
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
			if (composite.isInsideBounds(mousePos))//и при этом координата курсора попадает в спрайт
			{
				std::cout << "isClicked!\n";//выводим в консоль сообщение об этом
				composite.setDiff(mousePos.x, mousePos.y);
				
				//dX = mousePos.x - composite.getPosition().x;//делаем разность между позицией курсора и спрайта.для корректировки нажатия
				//dY = mousePos.y - composite.getPosition().y;//тоже самое по игреку
				isMove = true;//можем двигать спрайт	
				cout << "compositePos: " << composite.getPosition().x << " " << composite.getPosition().y << endl;
			}
		}

		if (event.type == Event::MouseButtonReleased) {//если отпустили клавишу
			if (event.key.code == Mouse::Left) //а именно левую
				isMove = false; //то не можем двигать спрайт	
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
			composite.addAll(allShapesVector);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
			composite.removeAll();
		}
	}
	if (isMove) {//если можем двигать
		//composite.setPosition(mousePos.x - dX, mousePos.y - dY);//двигаем спрайт по Х
		composite.setPosition(mousePos.x, mousePos.y);
	}
}

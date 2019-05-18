#include "stdafx.h"
#include "AppCommand.h"

void AppCommand::perform(PanelButton * button, CompositeShape *composite, bool *isMove, Vector2i mousePos, vector<IShape*> &allShapesVector)
{
	int code = button->getFunctCode();
	if (code == move_button)
		setMoveMode(composite);
	else if (code == new_triangle)
		createTriangle(allShapesVector);
	else if (code == new_rectangle)
		createRectangle(allShapesVector);
	else if (code == new_circle)
		createCircle(allShapesVector);
	else if (code == red_color)
		setColor(sf::Color::Red, composite);
	else if (code == blue_color)
		setColor(sf::Color::Blue, composite);
	else if (code == yellow_color)
		setColor(sf::Color::Yellow, composite);
	else if (code == line_1)
		setOutLineSize(1, composite);
	else if (code == line_3)
		setOutLineSize(3, composite);
	else if (code == line_5)
		setOutLineSize(5, composite);
}

void AppCommand::setColor(sf::Color shapeColor, CompositeShape * composite)
{
	composite->setColor(shapeColor);
}

void AppCommand::setOutLineSize(int lineSize, CompositeShape * composite)
{
	composite->setOutlineSize(lineSize);
}

void AppCommand::createCircle(vector<IShape*>& allShapesVector)
{
	vector<vector<int>> standartParams = { {700,0}, {50} };
	IShape* circle = new ShapeCircle(standartParams);
	IShape* circleDecorator = new DecoratorShape(circle);
	allShapesVector.push_back(circleDecorator);
}

void AppCommand::createRectangle(vector<IShape*>& allShapesVector)
{
	vector<vector<int>> standartParams = { { 700,100 },{ 800, 200 } };
	IShape* rectangle = new ShapeRectangle(standartParams);
	IShape* rectangleDecorator = new DecoratorShape(rectangle);
	allShapesVector.push_back(rectangleDecorator);
}

void AppCommand::createTriangle(vector<IShape*>& allShapesVector)
{
	vector<vector<int>> standartParams = { { 700, 300 }, { 750,200 },{ 800, 300 } };
	IShape* triangle = new ShapeTriangle(standartParams);
	IShape* triangleDecorator = new DecoratorShape(triangle);
	allShapesVector.push_back(triangleDecorator);
}

void AppCommand::setMoveMode(CompositeShape * composite)
{
	if (composite->canMove())
		composite->unsetMoveMode();
	else
		composite->setMoveMode();
}

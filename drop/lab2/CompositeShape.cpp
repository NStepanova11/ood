#include "stdafx.h"
#include "CompositeShape.h"
#include <iterator>
#include <iostream>

using namespace std;

void CompositeShape::add(IShape * shape)
{
	shapesContainer.push_back(shape);
	shape->selectShape();
}

void CompositeShape::addAll(vector<IShape*> allShapes)
{
	shapesContainer = allShapes;
	for (auto child : shapesContainer) {
		child->selectShape();
	}
}

void CompositeShape::remove(IShape *shape)
{
	//cout << "container size begin: " << shapesContainer.size() << endl;
	for (std::vector<IShape*>::iterator it = shapesContainer.begin(); it != shapesContainer.end(); it++)
	{
		if (*it == shape)
		{
			//delete *it;
			shape->unselectShape();
			shapesContainer.erase(it);
			break;
		}
	}
	//cout << "container size: " << shapesContainer.size() << endl;
}

void CompositeShape::removeAll()
{
	unselectShape();
	shapesContainer.clear();
}

void CompositeShape::move(int x, int y)
{
	for (auto child: shapesContainer)
	{
		//child->setX(x);
		//child->setY(y);
	}
}

void CompositeShape::draw(RenderWindow & window)
{
	for (auto child : shapesContainer) {
		child->draw(window);
	}
}

/*
int CompositeShape::getX()
{
	if (shapesContainer.size() == 0) {
		return 0;
	}
	int x = shapesContainer[0]->getX();
	for (auto child : shapesContainer) {
		if (child->getX() < x) {
			x = child->getX();
		}
	}
	return x;
}

int CompositeShape::getY()
{	
	if (shapesContainer.size() == 0) {
		return 0;
	}
	int y = shapesContainer[0]->getY();
	for (auto child : shapesContainer) {
		if (child->getY() < y) {
			y = child->getY();
		}
	}
	return y;
}

*/

int CompositeShape::getHeight()
{
	int maxHeight = 0;
	int y = getPosition().y;
	for (auto child : shapesContainer) {
		int childsRelativeY = child->getPosition().y - y;
		int childHeight = childsRelativeY + child->getHeight();
		if (childHeight > maxHeight) {
			maxHeight = childHeight;
		}
	}
	//cout << "maxHeight: " << maxHeight << endl;
	return maxHeight;
}

int CompositeShape::getWidth()
{
	int maxWidth = 0;
	int x = getPosition().x;
	for (auto child : shapesContainer) {
		int childsRelativeX = child->getPosition().x - x;
		int childWidth = childsRelativeX + child->getWidth();
		if (childWidth > maxWidth) {
			maxWidth = childWidth;
		}
	}
	return maxWidth;
}

bool CompositeShape::isSelected()
{
	return false;
}

void CompositeShape::selectShape()
{
	for (auto shape: shapesContainer)
	{
		shape->selectShape();
	}
}

void CompositeShape::unselectShape()
{
	for (auto shape : shapesContainer) {
		shape->unselectShape();
	}
}

bool CompositeShape::isInsideBounds(Vector2i pos)
{
	int minX = getPosition().x;
	int minY = getPosition().y;
	int maxX = minX + getWidth();
	int maxY = minY + getHeight();
	if ((pos.x >= minX && pos.x <= maxX) && (pos.y >= minY && pos.y <= maxY)) {
		return true;
	}
	return false;
}

void CompositeShape::setPosition(int mouseX, int mouseY)
{
	for (auto child : shapesContainer) {
		/*mousePos.x - dX, mousePos.y - dY*/
		int xx = mouseX - child->getDx();
		int yy = mouseY - child->getDy();
		child->setPosition(xx, yy);
		//cout << xx <<"  "<< yy << endl;
	}
}

Vector2i CompositeShape::getPosition()
{
	if (shapesContainer.size() == 0) {
		return Vector2i(0,0);
	}

	int x = shapesContainer[0]->getPosition().x;
	int y = shapesContainer[0]->getPosition().y;
	
	for (auto child : shapesContainer) {
		if (child->getPosition().x < x) {
			x = child->getPosition().x;
		}
		if (child->getPosition().y < y) {
			y = child->getPosition().y;
		}
	}
	return Vector2i(x, y);
}

void CompositeShape::drawFrame(RenderWindow & window)
{
	RectangleShape frame;
	frame.setSize(Vector2f(getWidth(), getHeight()));
	frame.setPosition(getPosition().x, getPosition().y);
	frame.setOutlineThickness(3);
	frame.setFillColor(Color::Transparent);
	frame.setOutlineColor(Color::White);
	window.draw(frame);
}

void CompositeShape::calculateCoordDiff(Vector2i mousePos)
{
	
}

void CompositeShape::setDiff(int mouseX, int mouseY)
{
	for (auto child :shapesContainer)
	{
		int dX = mouseX - child->getPosition().x;//делаем разность между позицией курсора и спрайта.для корректировки нажатия
		int dY = mouseY - child->getPosition().y;
		child->setDiff(dX, dY);
	}
}

int CompositeShape::getDx()
{
	return 0;
}

int CompositeShape::getDy()
{
	return 0;
}

/*
void CompositeShape::setX(int x)
{
	for (auto child : shapesContainer) {
		child->setX(x);
	}
}

void CompositeShape::setY(int y)
{
	for (auto child : shapesContainer) {
		child->setY(y);
	}
}

void CompositeShape::setPosition(Vector2i pos)
{
	for (auto child : shapesContainer)
	{
		child->setPosition(pos);
	}
}

*/
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
	for (std::vector<IShape*>::iterator it = shapesContainer.begin(); it != shapesContainer.end(); it++)
	{
		if (*it == shape)
		{
			shape->unselectShape();
			shapesContainer.erase(it);
			break;
		}
	}
}

void CompositeShape::removeAll()
{
	unselectShape();
	shapesContainer.clear();
}

void CompositeShape::draw(RenderWindow & window)
{
	for (auto child : shapesContainer) {
		child->draw(window);
	}
}

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
		int xx = mouseX - child->getDx();
		int yy = mouseY - child->getDy();
		child->setPosition(xx, yy);
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
	frame.setOutlineThickness(2);
	frame.setFillColor(Color::Transparent);
	frame.setOutlineColor(Color::White);
	window.draw(frame);
}

void CompositeShape::setDiff(int mouseX, int mouseY)
{
	for (auto child :shapesContainer)
	{
		int dX = mouseX - child->getPosition().x;
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

void CompositeShape::setColor(sf::Color shapeColor)
{
	for (auto child : shapesContainer) {
		child->setColor(shapeColor);
	}
}

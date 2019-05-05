#include "stdafx.h"
#include "CompositeShape.h"

void CompositeShape::add(IShape * shape)
{
	shapesContainer.push_back(shape);
}

void CompositeShape::draw(RenderWindow & window)
{
	for (auto child : shapesContainer) {
		child->draw(window);
	}
}

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

int CompositeShape::getHeight()
{
	return 0;
}

int CompositeShape::getWidth()
{
	return 0;
}

bool CompositeShape::isSelected()
{
	return false;
}

void CompositeShape::changeFocus()
{
	
}

bool CompositeShape::isInsideBounds(Vector2i pos)
{
	for (auto child : shapesContainer) {
		if (child->isInsideBounds(pos)) {
			return true;
		}
	}
	return false;
}

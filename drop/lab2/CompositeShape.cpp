#include "stdafx.h"
#include "CompositeShape.h"
#include <iterator>

void CompositeShape::add(IShape * shape)
{
	shapesContainer.push_back(shape);
	shape->selectShape();
	//unique_ptr<IShape> shape_ptr(shape);
	//shape_ptr->selectShape();
	//shapesCont.push_back(move(shape_ptr));
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
	cout << "container size begin: " << shapesContainer.size() << endl;
	/*for (auto &child : shapesCont) {
		if (child.get() == shape) {
			child.get()->unselectShape();
		}
	}*/
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
	cout << "container size: " << shapesContainer.size() << endl;
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
		child->setX(x);
		child->setY(y);
	}
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
	int maxHeight = 0;
	int y = getY();
	for (auto child : shapesContainer) {
		int childsRelativeY = child->getY() - y;
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
	int x = getX();
	for (auto child : shapesContainer) {
		int childsRelativeX = child->getX() - x;
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

void CompositeShape::changeFocus()
{
	
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
	int minX = getX();
	int minY = getY();
	int maxX = minX + getWidth();
	int maxY = minY + getHeight();
	if ((pos.x >= minX && pos.x <= maxX) && (pos.y >= minY && pos.y <= maxY)) {
		return true;
	}
	return false;
}

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


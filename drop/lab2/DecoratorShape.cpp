#include "stdafx.h"
#include "DecoratorShape.h"

DecoratorShape::DecoratorShape(IShape * shape)
	:m_shape(shape)
{
}

void DecoratorShape::draw(RenderWindow & window)
{
	m_shape->draw(window);
}

/*int DecoratorShape::getX()
{
	return m_shape->getX();
}

int DecoratorShape::getY()
{
	return m_shape->getY();
}
*/

int DecoratorShape::getHeight()
{
	return m_shape->getHeight();
}

int DecoratorShape::getWidth()
{
	return m_shape->getWidth();
}

bool DecoratorShape::isSelected()
{
	return m_shape->isSelected();
}

void DecoratorShape::selectShape()
{
	m_shape->selectShape();
}

void DecoratorShape::unselectShape()
{
	m_shape->unselectShape();
}

bool DecoratorShape::isInsideBounds(Vector2i pos)
{
	return m_shape->isInsideBounds(pos);
}

void DecoratorShape::setPosition(int x, int y)
{
	m_shape->setPosition(x, y);
}

Vector2i DecoratorShape::getPosition()
{
	return m_shape->getPosition();
}

/*
void DecoratorShape::setX(int x)
{
	m_shape->setX(x);
}

void DecoratorShape::setY(int y)
{
	m_shape->setY(y);
}

void DecoratorShape::setPosition(Vector2i pos)
{
	m_shape->setPosition(pos);
}
*/
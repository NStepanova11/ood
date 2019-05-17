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

void DecoratorShape::setDiff(int x, int y)
{
	m_shape->setDiff(x, y);
}

int DecoratorShape::getDx()
{
	return m_shape->getDx();
}

int DecoratorShape::getDy()
{
	return m_shape->getDy();
}

void DecoratorShape::setColor(sf::Color shapeColor)
{
	m_shape->setColor(shapeColor);
}

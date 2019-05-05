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

int DecoratorShape::getX()
{
	return m_shape->getX();
}

int DecoratorShape::getY()
{
	return m_shape->getY();
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

void DecoratorShape::changeFocus()
{
	m_shape->changeFocus();
}

bool DecoratorShape::isInsideBounds(Vector2i pos)
{
	return m_shape->isInsideBounds(pos);
}

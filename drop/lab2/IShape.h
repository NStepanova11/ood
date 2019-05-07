#pragma once
#include <SFML/Graphics.hpp>
#include "PPoint.h"
#include <vector>
#include <memory>
#include <iostream>

using namespace sf;
using namespace std;

class IShape
{
public:
	virtual void draw(RenderWindow &window) = 0;
	virtual int getHeight() = 0;
	virtual int getWidth() = 0;
	virtual bool isSelected() = 0;
	virtual void selectShape() = 0;
	virtual void unselectShape() = 0;
	virtual bool isInsideBounds(Vector2i pos) = 0;
	virtual void setPosition(int x, int y) = 0;
	virtual Vector2i getPosition() = 0;
	virtual void setDiff(int x, int y) = 0;
	virtual int getDx() = 0;
	virtual int getDy() = 0;
};

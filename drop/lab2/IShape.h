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
	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual int getHeight() = 0;
	virtual int getWidth() = 0;
	virtual bool isSelected() = 0;
	virtual void changeFocus() = 0;
	virtual bool isInsideBounds(Vector2i pos) = 0;
};

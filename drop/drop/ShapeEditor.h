#pragma once
#include <SFML/Graphics.hpp>
#include "Circle.h"

using namespace std;
using namespace sf;

class ShapeEditor
{
public:
	void renderWin();
	void checkEvent(RenderWindow &window, Circle &circle);
};


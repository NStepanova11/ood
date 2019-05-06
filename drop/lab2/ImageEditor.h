#pragma once
#include <SFML/Graphics.hpp>
#include "IShape.h"
#include "DecoratorShape.h"
#include "ShapeCircle.h"
#include "ShapeRectangle.h"
#include "ShapeTriangle.h"
#include "CompositeShape.h"

class ImageEditor
{
public:
	void renderWin();
	void checkEvent(RenderWindow &window, vector<IShape*> &allShapesVector, CompositeShape &composite);
};


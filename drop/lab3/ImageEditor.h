#pragma once
#include <SFML/Graphics.hpp>
#include "IShape.h"
#include "DecoratorShape.h"
#include "ShapeCircle.h"
#include "ShapeRectangle.h"
#include "ShapeTriangle.h"
#include "CompositeShape.h"
#include "FileReader.h"
#include "AppPanel.h"
#include "AppCommand.h"

class ImageEditor
{
public:
	void renderWin();
	void checkEvent(RenderWindow &window, vector<IShape*> &allShapesVector, CompositeShape &composite,
		float &dX, float &dY, bool &isMove, Vector2i &mousePos, AppPanel &panel);
	void getShapesFromFile(vector<IShape*> &dShapes);
	void drawShapes(RenderWindow &window, vector<IShape*> &dShapes, CompositeShape &composite);
};


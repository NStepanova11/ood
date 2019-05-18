#pragma once
#include "PanelButton.h"
#include "CompositeShape.h"
#include "ShapeCircle.h"
#include "ShapeRectangle.h"
#include "ShapeTriangle.h"
#include "DecoratorShape.h"
#include <vector>

class AppCommand
{
public:
	static void perform(PanelButton * button, CompositeShape * composite, bool *isMove, Vector2i mousePos, vector<IShape*> &allShapesVector);
	static void setColor(sf::Color shapeColor, CompositeShape * composite);
	static void setOutLineSize(int lineSize, CompositeShape * composite);
	static void createCircle(vector<IShape*> &allShapesVector);
	static void createRectangle(vector<IShape*>& allShapesVector);
	static void createTriangle(vector<IShape*>& allShapesVector);
	static void setMoveMode(CompositeShape * composite);
};


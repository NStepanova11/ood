#pragma once
#include "PanelButton.h"
#include "CompositeShape.h"

class AppCommand
{
public:
	static void perform(PanelButton * button, CompositeShape * composite, bool *isMove, Vector2i mousePos);
	static void setColor(sf::Color shapeColor, CompositeShape * composite);
};


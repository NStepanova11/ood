#pragma once
#include "PPoint.h"
#include <SFML\Graphics.hpp>
#include <map>
#include <string>
#include "..\drop\const.h"
#include <iostream>

using namespace sf;
using namespace std;

class PanelButton
{
private:
	PPoint left_top;
	int funct_code;
	int width;
	int height;
	RectangleShape buttonShape;
	map<int, string> buttonText;
	bool isClicked;

public:
	PanelButton(int x, int y, int code);
	void drawButton(RenderWindow &window);
	void setButtonDesign(RenderWindow &window);
	map<int, string> setButtonText();
	RectangleShape* getButton();
	int getFunctCode();
	void selectButton();
	void unselectButton();
	bool isSelected();
};


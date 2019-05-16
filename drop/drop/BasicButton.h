#pragma once
#include <SFML\Graphics.hpp>
#include "CPoint.h"
#include "const.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;
using namespace sf;

class BasicButton
{
private:
	CCPoint left_top;
	int funct_code;
	int width;
	int height;
	RectangleShape buttonShape;
	map<int, string> buttonText;
	bool isClicked;

public:
	BasicButton(int x, int y, int code);
	void drawButton(RenderWindow &window);
	void setButtonDesign(RenderWindow &window);
	map<int, string> setButtonText();
	RectangleShape* getButton();
	int getFunctCode();
	void selectButton();
	void unselectButton();
	bool isSelected();
};


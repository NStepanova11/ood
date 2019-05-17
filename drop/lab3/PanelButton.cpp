#include "stdafx.h"
#include "PanelButton.h"

PanelButton::PanelButton(int x, int y, int code)
	:left_top(x, y)
	, funct_code(code)
	, width(BUTTON_WIDTH)
	, height(BUTTON_HEIGHT)
	, isClicked(false)
	, buttonText(setButtonText())
{
}

void PanelButton::drawButton(RenderWindow & window)
{
	buttonShape.setSize(Vector2f(width, height));
	buttonShape.setPosition(left_top.getX(), left_top.getY());
	buttonShape.setOutlineColor(Color::Black);
	if (!isClicked)
		buttonShape.setFillColor(sf::Color::Blue);
	else
		buttonShape.setFillColor(sf::Color::Cyan);
	buttonShape.setOutlineThickness(2);
	window.draw(buttonShape);
	setButtonDesign(window);
}

void PanelButton::setButtonDesign(RenderWindow &window)
{
	sf::Text text;
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		cout << "no font" << endl;
	}

	text.setFont(font);
	text.setCharacterSize(16);
	text.setColor(sf::Color::White);
	text.setPosition(left_top.getX(), left_top.getY());
	string textString = "";
	
	textString = buttonText.find(funct_code)->second;
	text.setString(textString);
	window.draw(text);
}

map<int, string> PanelButton::setButtonText()
{
	map<int, string> bText;
	bText.insert({ move_button, "move" });
	bText.insert({ new_triangle, "triangle" });
	bText.insert({ new_rectangle, "rectangle" });
	bText.insert({ new_circle, "circle" });
	bText.insert({ red_color, "red" });
	bText.insert({ blue_color, "blue" });
	bText.insert({ yellow_color, "yellow" });
	bText.insert({ line_1, "1px" });
	bText.insert({ line_3, "3px" });
	bText.insert({ line_5, "5px" });
	return bText;
}

RectangleShape* PanelButton::getButton()
{
	return &buttonShape;
}

int PanelButton::getFunctCode()
{
	return funct_code;
}

void PanelButton::selectButton()
{
	isClicked = true;
}

void PanelButton::unselectButton()
{
	isClicked = false;
}

bool PanelButton::isSelected()
{
	return isClicked;
}

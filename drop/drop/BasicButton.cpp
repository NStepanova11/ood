#include "BasicButton.h"

BasicButton::BasicButton(int x, int y, int code)
:left_top(x, y)
,funct_code(code)
,width(BUTTON_WIDTH)
,height(BUTTON_HEIGHT)
,isClicked(false)
,buttonText(setButtonText())
{
}

void BasicButton::drawButton(RenderWindow & window)
{
	buttonShape.setSize(Vector2f(width, height));
	buttonShape.setPosition(left_top.getX(), left_top.getY());
	buttonShape.setOutlineColor(Color::Black);
	if(!isClicked)
		buttonShape.setFillColor(sf::Color::Blue);
	else
		buttonShape.setFillColor(sf::Color::Cyan);
	buttonShape.setOutlineThickness(2);
	window.draw(buttonShape);
	setButtonDesign(window);
}

void BasicButton::setButtonDesign(RenderWindow &window)
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
	//cout << funct_code << endl;
	/*switch (funct_code)
	{
	case move_button:
		cout << "move" << endl;
		textString = "move";
	case new_triangle:
		cout << "t" << endl;
		textString = "t";
	case new_rectangle:
		cout << "r" << endl;
		textString = "r";
	case new_circle:
		cout << "c" << endl;
		textString = "c";
	case red_color:
		cout << "red" << endl;
		textString = "red";
	case blue_color:
		cout << "blue" << endl;
		textString = "blue";
	case yellow_color:
		cout << "yelw" << endl;
		textString = "yelw";
	case line_1:
		cout << "1px" << endl;
		textString = "1px";
	case line_3:
		cout << "3px" << endl;
		textString = "3px";
	case line_5:
		cout << "5px" << endl;
		textString = "5px";
	default:
		break;
	}*/

	textString = buttonText.find(funct_code)->second;
	text.setString(textString);
	window.draw(text);
}

map<int, string> BasicButton::setButtonText()
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

RectangleShape* BasicButton::getButton()
{
	return &buttonShape;
}

int BasicButton::getFunctCode()
{
	return funct_code;
}

void BasicButton::selectButton()
{
	isClicked = true;
}

void BasicButton::unselectButton()
{
	isClicked = false;
}

bool BasicButton::isSelected()
{
	return isClicked;
}

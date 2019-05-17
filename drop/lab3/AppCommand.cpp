#include "stdafx.h"
#include "AppCommand.h"

void AppCommand::perform(PanelButton * button, CompositeShape *composite, bool *isMove, Vector2i mousePos)
{
	int code = button->getFunctCode();
	if (code == move_button)
		cout << "move" << endl;
	else if (code == new_triangle)
		cout << "new_triangle" << endl;
	else if (code == new_rectangle)
		cout << "new_rectangle" << endl;
	else if (code == new_circle)
		cout << "new_circle" << endl;
	else if (code == red_color)
		setColor(sf::Color::Red, composite);
	else if (code == blue_color)
		setColor(sf::Color::Blue, composite);
	else if (code == yellow_color)
		setColor(sf::Color::Yellow, composite);
	else if (code == line_1)
		setOutLineSize(1, composite);
	else if (code == line_3)
		setOutLineSize(3, composite);
	else if (code == line_5)
		setOutLineSize(5, composite);
}

void AppCommand::setColor(sf::Color shapeColor, CompositeShape * composite)
{
	composite->setColor(shapeColor);
}

void AppCommand::setOutLineSize(int lineSize, CompositeShape * composite)
{
	composite->setOutlineSize(lineSize);
}

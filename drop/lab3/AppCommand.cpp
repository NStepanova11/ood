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
		cout << "line_1" << endl;
	else if (code == line_3)
		cout << "line_3" << endl;
	else if (code == line_5)
		cout << "line_5" << endl;
}

void AppCommand::setColor(sf::Color shapeColor, CompositeShape * composite)
{
	composite->setColor(shapeColor);
}

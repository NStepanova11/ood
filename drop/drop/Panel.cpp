#include "Panel.h"
#include "iostream"

using namespace std;

Panel::Panel()
	:panelList(createPanel())
	,isButtonClicked(false)
{
}

vector<BasicButton*> Panel::createPanel()
{
	vector<BasicButton*> buttons;
	for (int id=move_button; id<=line_5; id++)
	{
		BasicButton* button = new BasicButton(0, BUTTON_HEIGHT*id, id);
		buttons.push_back(button);
	}
	width = BUTTON_WIDTH;
	height = buttons.size()*BUTTON_HEIGHT;
	return buttons;
}

void Panel::drawPanel(RenderWindow & window)
{
	/*RectangleShape panel;
	panel.setSize(Vector2f(width, height));
	panel.setPosition(0, 0);
	//panel.setOutlineColor(Color::Red);
	panel.setOutlineThickness(2);
	panel.setFillColor(Color::Transparent);
	window.draw(panel);
	*/
	for (auto &button : panelList)
	{
		button->drawButton(window);
	}
}

/*bool Panel::isPanelButtonClicked(Vector2f mousePos)
{
	for (auto &button: panelList)
	{
		if (button->getButton()->getGlobalBounds().contains(mousePos.x, mousePos.y)) {
			{
				return true;
			}
		}
	}
}*/

BasicButton * Panel::getClickedButton(Vector2i mousePos)
{
	for (auto button : panelList)
	{
		if (button->getButton()->getGlobalBounds().contains(mousePos.x, mousePos.y)) {
			{
				return button;
			}
		}
	}
}

bool Panel::isInsideBounds(Vector2i mousePos)
{
	if ((mousePos.x >= 0 && mousePos.x <= width) && (mousePos.y >= 0 && mousePos.y <= height)) {
		return true;
	}
	return false;
}

void Panel::unselectAllButton()
{
	for (auto &button : panelList)
	{
		button->unselectButton();
	}
}

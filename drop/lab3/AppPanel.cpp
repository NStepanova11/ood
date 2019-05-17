#include "stdafx.h"
#include "AppPanel.h"
#include "iostream"

using namespace std;

AppPanel::AppPanel()
	:panelList(createPanel())
	, isButtonClicked(false)
{
}

vector<PanelButton*> AppPanel::createPanel()
{
	vector<PanelButton*> buttons;
	for (int id = move_button; id <= line_5; id++)
	{
		PanelButton* button = new PanelButton(0, BUTTON_HEIGHT*id, id);
		buttons.push_back(button);
	}
	width = BUTTON_WIDTH;
	height = buttons.size()*BUTTON_HEIGHT;
	return buttons;
}

void AppPanel::drawPanel(RenderWindow & window)
{
	for (auto &button : panelList)
	{
		button->drawButton(window);
	}
}

PanelButton * AppPanel::getClickedButton(Vector2i mousePos)
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

bool AppPanel::isInsideBounds(Vector2i mousePos)
{
	if ((mousePos.x >= 0 && mousePos.x <= width) && (mousePos.y >= 0 && mousePos.y <= height)) {
		return true;
	}
	return false;
}

void AppPanel::unselectAllButton()
{
	for (auto &button : panelList)
	{
		button->unselectButton();
	}
}

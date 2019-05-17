#pragma once
#include "PanelButton.h"
#include <vector>
#include "..\drop\const.h"

using namespace std;

class AppPanel
{
private:
	vector<PanelButton*> panelList;
	bool isButtonClicked;
	int width;
	int height;
public:
	AppPanel();
	vector<PanelButton*> createPanel();
	void drawPanel(RenderWindow &window);
	PanelButton * getClickedButton(Vector2i mousePos);
	bool isInsideBounds(Vector2i mousePos);
	void unselectAllButton();
};


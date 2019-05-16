#pragma once
#include "BasicButton.h"
#include <vector>
#include "const.h"

using namespace std;

class Panel
{
private:
	vector<BasicButton*> panelList;
	bool isButtonClicked;
	int width;
	int height;
public:
	Panel();
	vector<BasicButton*> createPanel();
	void drawPanel(RenderWindow &window);
	//bool isPanelButtonClicked(Vector2f mousePos);
	BasicButton * getClickedButton(Vector2i mousePos);
	bool isInsideBounds(Vector2i mousePos);
	void unselectAllButton();
};


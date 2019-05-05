#pragma once
#include "IShape.h"

class ShapeCircle :	public IShape
{
private:
	PPoint top_left;
	int radius;
	bool selected;
public:
	ShapeCircle(vector<vector<int>> points);
	void draw(RenderWindow &window) override;
	int getX() override;
	int getY() override;
	int getHeight() override;
	int getWidth() override;
	bool isSelected() override;
	void changeFocus() override;
	bool isInsideBounds(Vector2i pos) override;
};

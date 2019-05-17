#pragma once
#include "IShape.h"

class ShapeCircle :	public IShape
{
private:
	PPoint top_left;
	int radius;
	bool selected;
	CircleShape shape;
	int dx = 0;
	int dy = 0;
	Color shapeColor;

public:
	ShapeCircle(vector<vector<int>> points);
	void draw(RenderWindow &window) override;
	int getHeight() override;
	int getWidth() override;
	bool isSelected() override;
	void selectShape() override;
	void unselectShape() override;
	bool isInsideBounds(Vector2i pos) override;
	void setPosition(int x, int y) override;
	Vector2i getPosition() override;
	void setDiff(int x, int y) override;
	int getDx() override;
	int getDy() override;
	void setColor(Color shColor) override;
};


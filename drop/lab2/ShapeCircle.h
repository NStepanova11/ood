#pragma once
#include "IShape.h"

class ShapeCircle :	public IShape
{
private:
	PPoint top_left;
	int radius;
	bool selected;
	CircleShape shape;
public:
	ShapeCircle(vector<vector<int>> points);
	void draw(RenderWindow &window) override;
	int getHeight() override;
	int getWidth() override;
	bool isSelected() override;
	void selectShape() override;
	void unselectShape() override;
	bool isInsideBounds(Vector2i pos) override;
	//void setX(int x) override;
	//void setY(int y) override;
	//int getX() override;
	//int getY() override;
	void setPosition(int x, int y) override;
	Vector2i getPosition() override;
};


#pragma once
#include "IShape.h"
class ShapeTriangle : public IShape
{
private:
	PPoint a;
	PPoint b;
	PPoint c;
	int sideAB;
	int sideBC;
	int sideCA;
	bool selected;
	ConvexShape shape;
	int moveCoordsX;
	int moveCoordsY;
	int dx = 0;
	int dy = 0;
	Color shapeColor;
	int outLine;
	int minX, minY;

public:
	ShapeTriangle(vector<vector<int>> points);
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
	void setOutlineSize(int lineSize) override;
};


#pragma once
#include "IShape.h"
class CompositeShape :	public IShape
{
private:
	vector<IShape*> shapesContainer;
	unique_ptr<IShape> shape_ptr;
	vector<unique_ptr<IShape>> shapesCont;
public:
	void add(IShape *shape);
	void addAll(vector<IShape*> allShapes);
	void remove(IShape *shape);
	void removeAll();
	void move(int x, int y);
	void draw(RenderWindow &window) override;
	int getX() override;
	int getY() override;
	int getHeight() override; //return 0
	int getWidth() override; //return 0
	bool isSelected() override; //return 0
	void changeFocus() override; //return 0
	void selectShape() override;
	void unselectShape() override;
	virtual bool isInsideBounds(Vector2i pos) override;
	void setX(int x) override;
	void setY(int y) override;
};


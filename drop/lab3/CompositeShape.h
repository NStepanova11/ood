#pragma once
#include "IShape.h"
#include "..\drop\const.h"

class CompositeShape :	public IShape
{
private:
	vector<IShape*> shapesContainer;
	unique_ptr<IShape> shape_ptr;
	vector<unique_ptr<IShape>> shapesCont;
	bool moveMode;
public:
	CompositeShape();
	void add(IShape *shape);
	void addAll(vector<IShape*> allShapes);
	void remove(IShape *shape);
	void removeAll();
	void draw(RenderWindow &window) override;
	int getHeight() override; 
	int getWidth() override;
	bool isSelected() override; 
	void selectShape() override;
	void unselectShape() override;
	virtual bool isInsideBounds(Vector2i pos) override;
	void setPosition(int x, int y) override;
	Vector2i getPosition() override;
	void drawFrame(RenderWindow &window);
	void setDiff(int x, int y) override;
	int getDx() override;
	int getDy() override;
	void setColor(sf::Color shapeColor) override;
	void setOutlineSize(int lineSize) override;
	void setMoveMode();
	void unsetMoveMode();
	bool canMove();
};


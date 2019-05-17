#pragma once
#include "IShape.h"
class DecoratorShape : public IShape
{
private:
	shared_ptr <IShape> m_shape;
	RenderWindow m_win;
public:
	DecoratorShape(IShape* shape);
	virtual void draw(RenderWindow &window);
	virtual int getHeight() override;
	virtual int getWidth() override;
	virtual bool isSelected() override;
	virtual void selectShape() override;
	virtual void unselectShape() override;
	virtual bool isInsideBounds(Vector2i pos) override;
	virtual void setPosition(int x, int y) override;
	virtual Vector2i getPosition() override;
	virtual void setDiff(int x, int y) override;
	virtual int getDx() override;
	virtual int getDy() override;
	virtual void setColor(sf::Color shapeColor) override;
	void setOutlineSize(int lineSize) override;
};


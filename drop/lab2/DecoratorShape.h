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
	virtual int getX() override;
	virtual int getY() override;
	virtual int getHeight() override;
	virtual int getWidth() override;
	virtual bool isSelected() override;
	virtual void changeFocus() override;
	virtual void selectShape() override;
	virtual void unselectShape() override;
	virtual bool isInsideBounds(Vector2i pos) override;
	virtual void setX(int x)  override;
	virtual void setY(int y)  override;
	virtual void setPosition(Vector2i pos) override;
};


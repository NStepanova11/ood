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
	virtual int getX();
	virtual int getY();
	virtual int getHeight();
	virtual int getWidth();
	virtual bool isSelected();
	virtual void changeFocus();
	virtual bool isInsideBounds(Vector2i pos) override;
};


#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "ShapeCircle.h"
#include "DecoratorShape.h"
#include "IShape.h"
#include "CompositeShape.h"
#include "ImageEditor.h"

using namespace sf;

int main()
{
	ImageEditor imageEditor;
	imageEditor.renderWin();
	return 0;
}
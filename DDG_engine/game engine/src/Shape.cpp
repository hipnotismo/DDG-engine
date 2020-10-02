#include "Shape.h"


Shape::Shape(SHAPES shape, Renderer* render)
{
	_shape = shape;
	_renderer = render;
	_color = WHITE;
}

Shape::~Shape()
{
}

SHAPES Shape::getsType()
{
	return _shape;
}

Color Shape::getColor()
{
	return _color;
}

void Shape::setColor(Color nColor)
{
	_color = nColor;
}

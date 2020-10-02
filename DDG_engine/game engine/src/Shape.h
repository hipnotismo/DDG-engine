
#ifndef SHAPE_H
#define SHAPE_H

#include "export.h"
#include "entity.h"
#include "global.h"

enum SHAPES
{
	TRIANGLE, RECTANGLE
};

class ENGINE_API Shape : public Entity {

public:
	Shape(SHAPES shape, Renderer* render);
	~Shape();
	
	SHAPES getsType();
	Color getColor();

	void setColor(Color nColor);

	SHAPES _shape;
	Color _color;
};


#endif // !WINDOW_H
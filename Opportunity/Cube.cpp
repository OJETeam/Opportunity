#include "Cube.h"

Cube::Cube(Vector2 position, float sideLength, Color color)
	: Object(position, Model({ Vector2(0, 0), Vector2(sideLength, 0), Vector2(0, sideLength), Vector2(0, sideLength), Vector2(sideLength, sideLength), Vector2(sideLength, position.y) }, color))
{
}

void Cube::Update()
{
}
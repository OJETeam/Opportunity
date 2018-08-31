#include "Cube.h"

Cube::Cube(Vector2 position, float sideLength, Color color)
	: Object(position, Model::Cube(sideLength, color)) 
{
}

void Cube::Update()
{
}
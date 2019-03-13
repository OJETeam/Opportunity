#include "Cube.h"
#include "Time.h"

Cube::Cube(Vector2 position, float sideLength, Color color) : Object(position, Model::Cube(sideLength, color))
{
}

void Cube::Update()
{
	//rotation += 1.0f * Time::DeltaTime();
}
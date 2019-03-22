#include "Cube.h"
#include "Time.h"

Cube::Cube(Vector2 position, float sideLength, Color color) : GameObject(position, Model::Cube(sideLength, color, Vector2(0, 0)))
{
}

void Cube::Update()
{
	//rotation += 1.0f * Time::DeltaTime();
}
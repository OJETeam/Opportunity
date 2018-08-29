#pragma once
#include "Object.h"

class Cube : public Object
{
public:
	Cube(Vector2 position, float sideLength, Color color);
	void Update() override;
};
#pragma once

#include "Object.h"
#include "Window.h"
#include "Camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Cube : public Object
{
public:
	Cube(Vector2 position, float sideLength, Color color);
	void Render();
	void Update() override;
};
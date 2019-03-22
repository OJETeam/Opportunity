#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "GameObject.h"
#include "Window.h"
#include "Camera.h"

class Cube : public GameObject
{
public:
	Cube(Vector2 position, float sideLength, Color color);
	void Update() override;
};
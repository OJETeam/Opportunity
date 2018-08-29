#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Vector2.h"

class Camera
{
public:
	static glm::mat4 ViewMatrix;

	static void MoveDelta(Vector2 delta);
	static void MoveTo(Vector2 pos);
};


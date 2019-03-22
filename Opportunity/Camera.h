#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Vector2.h"

class Camera
{
public:
	static glm::mat4 viewMatrix;
	static float speed;

	static void MoveBy(Vector2 delta);
	static void MoveTo(Vector2 pos);
	static void Update();
};
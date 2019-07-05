#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Vector2.h"

class Camera
{
private:
	static Vector2 position;
	static float scale;
public:
	static glm::mat4 viewMatrix;
	static float moveSpeed;
	static float scaleSpeed;

	static void Update();
	static void recalculateMatrix();
	static Vector2 getPosition();
	static void setPosition(const Vector2& position);
	static float getScale();
	static void setScale(float scale);
};
#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Vector2.h"

using namespace glm;

class Camera
{
private:
	static Vector2 position;
	static float scale;
public:
	static glm::mat4 viewMatrix;
	static glm::mat4 viewMatrixInverse;
	static float moveSpeed;
	static float scaleSpeed;

	static void Update();
	static void RecalculateMatrix();
	static Vector2 ScreenToWorldPoint(Vector2 screenPoint);
	static Vector2 getPosition();
	static void setPosition(const Vector2& position);
	static float getScale();
	static void setScale(float scale);
};
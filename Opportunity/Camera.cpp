#include "Camera.h"

glm::mat4 Camera::ViewMatrix = glm::mat4(1.0f);

void Camera::MoveDelta(Vector2 delta)
{
	ViewMatrix = glm::translate(ViewMatrix, glm::vec3(delta.x, delta.y, 0));
}

void Camera::MoveTo(Vector2 pos)
{
	ViewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(pos.x, pos.y, 0));
}

#include "Camera.h"
#include "Window.h"
#include "Time.h"

glm::mat4 Camera::viewMatrix = glm::mat4(1.0f);
float Camera::speed = 500;

void Camera::MoveBy(Vector2 delta)
{
	viewMatrix = glm::translate(viewMatrix, glm::vec3(-delta.x, -delta.y, 0));
}

void Camera::MoveTo(Vector2 pos)
{
	viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(-pos.x, -pos.y, 0));
}

void Camera::Update()
{
	const float delta = speed * Time::DeltaTime();
	Vector2 movement = Vector2(0, 0);

	if (glfwGetKey(Window::window, GLFW_KEY_UP) == GLFW_PRESS) //TODO migrate to input system
		movement.y += delta;
	else if (glfwGetKey(Window::window, GLFW_KEY_DOWN) == GLFW_PRESS)
		movement.y -= delta;

	if (glfwGetKey(Window::window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		movement.x += delta;
	else if (glfwGetKey(Window::window, GLFW_KEY_LEFT) == GLFW_PRESS)
		movement.x -= delta;

	MoveBy(movement);
}
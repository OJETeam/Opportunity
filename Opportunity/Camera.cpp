#include "Camera.h"
#include "Window.h"
#include "Time.h"

glm::mat4 Camera::viewMatrix = glm::mat4(1.0f);
Vector2 Camera::position = Vector2(0, 0);
float Camera::scale = 1.0f;
float Camera::moveSpeed = 500;
float Camera::scaleSpeed = 1;

void Camera::Update()
{
	const float deltaMovement = (moveSpeed * Time::DeltaTime()) / scale;
	Vector2 movement = position;

	if (glfwGetKey(Window::window, GLFW_KEY_UP) == GLFW_PRESS) //TODO migrate to input system
		movement.y += deltaMovement;
	else if (glfwGetKey(Window::window, GLFW_KEY_DOWN) == GLFW_PRESS)
		movement.y -= deltaMovement;

	if (glfwGetKey(Window::window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		movement.x += deltaMovement;
	else if (glfwGetKey(Window::window, GLFW_KEY_LEFT) == GLFW_PRESS)
		movement.x -= deltaMovement;

	setPosition(movement);

	const float deltaScale = (scaleSpeed * Time::DeltaTime()) * scale;
	float newScale = scale;

	if (glfwGetKey(Window::window, GLFW_KEY_EQUAL) == GLFW_PRESS)
		newScale += deltaScale;
	else if (glfwGetKey(Window::window, GLFW_KEY_MINUS) == GLFW_PRESS)
		newScale -= deltaScale;

	setScale(newScale);
}

void Camera::recalculateMatrix()
{
	glm::mat4 mat = glm::mat4(1.0f);

	mat = glm::translate(mat, glm::vec3((float)Window::width / 2, (float)Window::height / 2, 0));
	mat = glm::scale(mat, glm::vec3(scale, scale, 0));
	mat = glm::translate(mat, glm::vec3(-position.x, -position.y, 0));
	mat = glm::translate(mat, glm::vec3(-(float)Window::width / 2, -(float)Window::height / 2, 0));

	viewMatrix = mat;
}

Vector2 Camera::getPosition()
{
	return position;
}

void Camera::setPosition(const Vector2& position)
{
	Camera::position = position;

	recalculateMatrix();
}

float Camera::getScale()
{
	return scale;
}

void Camera::setScale(float scale)
{
	Camera::scale = scale;

	recalculateMatrix();
}
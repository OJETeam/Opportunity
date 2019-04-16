#include "Input.h"

Input::ButtonState Input::mouseButtons[mouseButtonCount];

void Input::Start()
{
	glfwSetKeyCallback(Window::window, KeyCallback);
}

Input::ButtonState Input::GetKeyState(unsigned int key)
{
	return keys[key];
}

bool Input::IsKeyPressed(unsigned int key)
{
	return keys[key] == ButtonState::Pressed;
}

bool Input::IsKeyHeld(unsigned int key)
{
	return keys[key] == ButtonState::Pressed || keys[key] == ButtonState::Held;
}

bool Input::IsKeyReleased(unsigned int key)
{
	return keys[key] == ButtonState::Released;
}

Input::ButtonState Input::GetMouseButtonState(unsigned int mouseButton)
{
	return mouseButtons[mouseButton];
}

void Input::KeyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods)
{
	if (key == GLFW_KEY_UNKNOWN) return;

	keys[key] = static_cast<ButtonState>(action);
}
#include "Input.h"

Input::ButtonState Input::mouseButtons[mouseButtonCount];

void Input::Start()
{
	glfwSetKeyCallback(Window::window, KeyCallback);
	glfwSetMouseButtonCallback(Window::window, MouseButtonCallback)
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

bool Input::IsMouseButtonPressed(unsigned mouseButton)
{
	return mouseButtons[mouseButton] == ButtonState::Pressed;
}

bool Input::IsMouseButtonHeld(unsigned mouseButton)
{
	return mouseButtons[mouseButton] == ButtonState::Pressed || mouseButtons[mouseButton] == ButtonState::Held;
}

bool Input::IsMouseButtonReleased(unsigned mouseButton)
{
	return mouseButtons[mouseButton] == ButtonState::Released;
}

void Input::KeyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods)
{
	if (key == GLFW_KEY_UNKNOWN) return;

	keys[key] = static_cast<ButtonState>(action);
}

void Input::MouseButtonCallback(GLFWwindow* window, int mouseButton, int action, int mods)
{
	ButtonState state = static_cast<ButtonState>(action);
	mouseButtons[mouseButton] = state;
}
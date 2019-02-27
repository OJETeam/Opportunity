#include "Input.h"

bool Input::mouseButttonsPrev[3];
MouseButtonState Input::mouseButtons[3];

bool Input::KeyPressed(int key)
{
	return glfwGetKey(Window::window, key) == GLFW_PRESS;
}

MouseButtonState Input::GetMouseButtonState(MouseButtons mouseButton)
{
	return mouseButtons[mouseButton];
}

void Input::Update()
{
	for (int i = 0; i < 3; ++i)
	{
		bool mouseButtonsCurrent = glfwGetMouseButton(Window::window, i) == GLFW_PRESS;
		if (mouseButtonsCurrent)
			if (!mouseButttonsPrev[i])
				mouseButtons[i] = MouseButtonState::Clicked;
			else
				mouseButtons[i] = MouseButtonState::Pressed;
		else
			mouseButtons[i] = MouseButtonState::Released;
		mouseButttonsPrev[i] = mouseButtonsCurrent;
	}
}
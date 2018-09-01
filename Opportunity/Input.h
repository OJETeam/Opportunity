#pragma once

#include <iostream>
#include <glm\glm.hpp>

#include "Window.h"

enum MouseButtons
{
	Left = GLFW_MOUSE_BUTTON_LEFT,
	Right = GLFW_MOUSE_BUTTON_RIGHT,
	Middle = GLFW_MOUSE_BUTTON_MIDDLE
};

enum MouseButtonState
{
	Released,
	Pressed,
	Clicked
};

class Input
{
private:
	static bool mouseButttonsPrev[3];
	static MouseButtonState mouseButtons[3];
public:
	static void Update();
	static MouseButtonState GetMouseButtonState(MouseButtons mouseButton);
	static bool KeyPressed(int key);
};
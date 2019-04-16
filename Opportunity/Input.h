#pragma once

#include <iostream>
#include <glm/glm.hpp>

#include "Window.h"

/*enum class MouseButtons //TODO return this enum
{
	Left = GLFW_MOUSE_BUTTON_LEFT,
	Right = GLFW_MOUSE_BUTTON_RIGHT,
	Middle = GLFW_MOUSE_BUTTON_MIDDLE,

};*/

class Input
{
public:
	enum class ButtonState
	{
		Pressed,
		Held,
		Released
	};
private:
	static const unsigned int keyCount = GLFW_KEY_LAST + 1;
	static const unsigned int mouseButtonCount = GLFW_MOUSE_BUTTON_LAST + 1;
	static ButtonState keys[keyCount];
	static ButtonState mouseButtons[mouseButtonCount];

	static void KeyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods);
	static void MouseButtonCallback(GLFWwindow* window, int mouseButton, int action, int mods);
public:
	static void Start();
	static ButtonState GetKeyState(unsigned int key); //TODO create an enum for all glfw keys
	static bool IsKeyPressed(unsigned int key);
	static bool IsKeyHeld(unsigned int key);
	static bool IsKeyReleased(unsigned int key);
	static ButtonState GetMouseButtonState(unsigned int mouseButton);
	static bool IsMouseButtonPressed(unsigned int mouseButton);
	static bool IsMouseButtonHeld(unsigned int mouseButton);
	static bool IsMouseButtonReleased(unsigned int mouseButton);
};
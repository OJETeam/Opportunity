#pragma once

#include <iostream>
#include <map>
#include <glm/glm.hpp>

#include "Window.h"
#include "Vector2.h"
#include "Object.h"

using namespace std;

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
		Released = GLFW_RELEASE,
		Pressed = GLFW_PRESS,
		Held = GLFW_REPEAT,
		Clicked
	};
private:
	static const unsigned int keyCount = GLFW_KEY_LAST + 1;
	static const unsigned int mouseButtonCount = GLFW_MOUSE_BUTTON_LAST + 1;
	static ButtonState keys[keyCount];
	static ButtonState mouseButtons[mouseButtonCount];
	static bool updateKeys;
	static bool updateMouseButtons;
	static Object* mouseOverObject;
	static map<int> // TODO implement Object mouse states (OnMouseEnter, OnMouseExit, OnMouseOver etc.). Find a way to store Object:State in a container

	static bool CheckObjectMouseCollision(Object* obj, Vector2 mousePos);

	static void KeyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods);
	static void MouseButtonCallback(GLFWwindow* window, int mouseButton, int action, int mods);
public:
	static void Start();
	static void Update();
	static ButtonState GetKeyState(unsigned int key); //TODO create an enum for all glfw keys
	static bool IsKeyPressed(unsigned int key);
	static bool IsKeyHeld(unsigned int key);
	static bool IsKeyReleased(unsigned int key);
	static bool IsKeyClicked(unsigned int key);
	static Vector2 GetMousePosition();
	static ButtonState GetMouseButtonState(unsigned int mouseButton);
	static bool IsMouseButtonPressed(unsigned int mouseButton);
	static bool IsMouseButtonHeld(unsigned int mouseButton);
	static bool IsMouseButtonReleased(unsigned int mouseButton);
	static bool IsMouseButtonClicked(unsigned int mouseButton);
};
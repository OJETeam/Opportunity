#include "Input.h"
#include "Game.h"
#include "Camera.h"

Input::ButtonState Input::keys[keyCount];
Input::ButtonState Input::mouseButtons[mouseButtonCount];
bool Input::updateKeys = false;
bool Input::updateMouseButtons = false;
Object* Input::mouseOverObject = nullptr;
Object* Input::mousePressObjects[mouseButtonCount];

void Input::Start()
{
	glfwSetKeyCallback(Window::window, KeyCallback);
	glfwSetMouseButtonCallback(Window::window, MouseButtonCallback);
}

void Input::Update()
{
	Object* newMouseOverObject = FirstObjectUnderMouse();

	InvokeMouseObjectEvents();

	if (updateKeys) // TODO move to function
	{
		for (ButtonState& state : keys)
		{
			if (state == ButtonState::Clicked)
				state = ButtonState::Released;
			else if (state == ButtonState::Pressed)
				state = ButtonState::Held;
		}
		updateKeys = false;
	}
	if (updateMouseButtons) // TODO move to function
	{
		for (ButtonState& state : mouseButtons)
		{
			if (state == ButtonState::Clicked)
				state = ButtonState::Released;
			else if (state == ButtonState::Pressed)
				state = ButtonState::Held;
		}
		updateMouseButtons = false;
	}
}

void Input::InvokeMouseObjectEvents()
{
	if (newMouseOverObject) // TODO set new mouse over object and call OnMouseExit on it

		for (unsigned int i = 0; i < mouseButtonCount; i++)
		{
			ButtonState state = mouseButtons[i];

			if (state == ButtonState::Pressed && mouseOverObject != nullptr)
			{
				mouseOverObject->OnMousePressed(i);
				mousePressObjects[i] = mouseOverObject;
			}
			else if (state == ButtonState::Held && mousePressObjects[i] != nullptr)
			{
				mousePressObjects[i]->OnMouseDrag(i);
			}
			else if (state == ButtonState::Clicked)
			{
				if (mouseOverObject != nullptr)
				{
					mouseOverObject->OnMouseReleased(i);

					if (mouseOverObject == mousePressObjects[i])
						mouseOverObject->OnMouseClicked(i);
				}

				mousePressObjects[i] = nullptr;
			}
		}
}

Object* Input::FirstObjectUnderMouse()
{
	Object* foundObject = nullptr;
	Vector2 mouseWorldPos = Camera::ScreenToWorldPoint(GetMousePosition());

	for (auto i = Game::GetScene()->guiObjectsBegin(); i != Game::GetScene()->guiObjectsEnd(); ++i)
	{
		if (IsMouseCollidingObject(*i, mouseWorldPos))
		{
			foundObject = *i;
			break;
		}
	}

	if (!foundObject)
	{
		for (auto i = Game::GetScene()->gameObjectsBegin(); i != Game::GetScene()->gameObjectsEnd(); ++i)
		{
			if (IsMouseCollidingObject(*i, mouseWorldPos))
			{
				foundObject = *i;
				break;
			}
		}
	}

	return foundObject;
}

bool Input::IsMouseCollidingObject(Object* obj, Vector2 mousePos)FUCK //TODO REWRITE FAST, SHITTY NAME, BAD CODE, SIDE EFFECTS!
{
	if (obj->collider == nullptr)
		return false;

	if (obj->collider->IsInCollider(mousePos))
	{
		if (mouseOverObject == obj)
		{
			obj->OnMouseOver();
			return true;
		}

		if (mouseOverObject != nullptr)
			mouseOverObject->OnMouseExit();

		obj->OnMouseEnter();
		mouseOverObject = obj;

		return true;
	}

	return false;
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
	return keys[key] == ButtonState::Held || keys[key] == ButtonState::Pressed;
}

bool Input::IsKeyReleased(unsigned int key)
{
	return keys[key] == ButtonState::Released || keys[key] == ButtonState::Clicked;
}

bool Input::IsKeyClicked(unsigned key)
{
	return keys[key] == ButtonState::Clicked;
}

Vector2 Input::GetMousePosition()
{
	double x, y;
	glfwGetCursorPos(Window::window, &x, &y);

	return Vector2((float)x, (float)y);
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
	return mouseButtons[mouseButton] == ButtonState::Held || mouseButtons[mouseButton] == ButtonState::Pressed;
}

bool Input::IsMouseButtonReleased(unsigned mouseButton)
{
	return mouseButtons[mouseButton] == ButtonState::Released || mouseButtons[mouseButton] == ButtonState::Clicked;
}

bool Input::IsMouseButtonClicked(unsigned mouseButton)
{
	return mouseButtons[mouseButton] == ButtonState::Clicked;
}

void Input::KeyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods)
{
	if (action == GLFW_REPEAT || action == GLFW_KEY_UNKNOWN) return;

	ButtonState state = static_cast<ButtonState>(action);
	ButtonState& currentState = keys[key];

	if (action == GLFW_PRESS)
	{
		if (currentState == ButtonState::Released || currentState == ButtonState::Clicked)
		{
			currentState = ButtonState::Pressed;
			updateKeys = true;
		}
	}
	else if (action == GLFW_RELEASE)
	{
		if (currentState == ButtonState::Held || currentState == ButtonState::Pressed)
		{
			currentState = ButtonState::Clicked;
			updateKeys = true;
		}
	}
}

void Input::MouseButtonCallback(GLFWwindow* window, int mouseButton, int action, int mods)
{
	ButtonState& currentState = mouseButtons[mouseButton];

	if (action == GLFW_PRESS)
	{
		if (currentState == ButtonState::Released || currentState == ButtonState::Clicked)
		{
			currentState = ButtonState::Pressed;
			updateMouseButtons = true;
		}
	}
	else if (action == GLFW_RELEASE)
	{
		if (currentState == ButtonState::Held || currentState == ButtonState::Pressed)
		{
			currentState = ButtonState::Clicked;
			updateMouseButtons = true;
		}
	}
}
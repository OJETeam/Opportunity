#include "TestGameObject.h"
#include "Camera.h"

TestGameObject::TestGameObject(Vector2 position, Model model) : GameObject(position, model)
{
}

void TestGameObject::Update()
{
}

void TestGameObject::OnMouseEnter()
{
	_color = model.color;
	model.color = Color(1, 1, 0);
	cout << "enter" << endl;
}

void TestGameObject::OnMouseOver()
{
}

void TestGameObject::OnMouseExit()
{
	model.color = _color;
	cout << "exit" << endl;
}

void TestGameObject::OnMousePressed(unsigned mouseButton)
{
	offsetPos = Camera::ScreenToWorldPoint(Input::GetMousePosition()) - position;
	prevPos = position;
	cout << "OnMousePressed " << to_string(mouseButton) << endl;
}

void TestGameObject::OnMouseDrag(unsigned mouseButton)
{
	position = Camera::ScreenToWorldPoint(Input::GetMousePosition()) - offsetPos;
	cout << "OnMouseDrag " << to_string(mouseButton) << endl;
}

void TestGameObject::OnMouseReleased(unsigned mouseButton)
{
	position = prevPos;
	cout << "OnMouseReleased " << to_string(mouseButton) << endl;
}

void TestGameObject::OnMouseClicked(unsigned mouseButton)
{
	cout << "OnMouseClicked " << to_string(mouseButton) << endl;
}

void TestGameObject::OnCollisionEnter(Object& obj)
{
}

void TestGameObject::OnCollisionExit(Object& obj)
{
}

void TestGameObject::OnCollisionStay(Object& obj)
{
}
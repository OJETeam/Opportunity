#pragma once
#include "GameObject.h"
#include "Input.h"

using namespace std;

class TestGameObject : public GameObject
{
public:
	TestGameObject(Vector2 position, Model model);
	void Update() override;
	void OnMouseEnter() override;
	void OnMouseOver() override;
	void OnMouseExit() override;
	void OnMousePressed(unsigned int mouseButton) override;
	void OnMouseHeld(unsigned int mouseButton) override;
	void OnMouseReleased(unsigned int mouseButton) override;
	void OnMouseClicked(unsigned int mouseButton) override;
	void OnCollisionEnter(Object& obj) override;
	void OnCollisionExit(Object& obj) override;
	void OnCollisionStay(Object& obj) override;

	Vector2 offsetPos;
	Vector2 prevPos;
	Color _color;
};
#pragma once
#include "Object.h"

class GameObject : public Object
{
public:
	GameObject(Vector2 position, Model model);
	void SetParent(GameObject& parent, bool reposition); //TODO RemoveParent
	GameObject* GetParent() const;
	void Render() override;
};
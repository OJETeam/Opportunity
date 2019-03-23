#pragma once
#include "Object.h"

class GameObject : public Object
{
private:
	GameObject* parent;
public:
	GameObject(Vector2 position, Model model);
	void SetParent(GameObject& parent, bool reposition);
	GameObject* GetParent() const;
	void Render() override;
};
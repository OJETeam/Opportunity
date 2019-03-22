#pragma once
#include "Object.h"

class GameObject : public Object
{
public:
	GameObject(Vector2 position, Model model);
	void Render() override;
};
#pragma once
#include "GameObject.h"

class Entity : public GameObject
{
public:
	Entity(Vector2 position, Model model);
};
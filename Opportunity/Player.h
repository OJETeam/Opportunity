#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(Vector2 position, Model model);
	void Update() override;
};
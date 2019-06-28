#pragma once
#include <vector>
#include "Vector2.h"

using namespace  std;

class Collider
{
private:
	virtual bool CheckCollision(const Collider& collider, bool& available) const = 0;
public:
	Collider();
	~Collider();

	bool IsColliding(const Collider& collider) const;
};
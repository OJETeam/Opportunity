#pragma once
#include <vector>
#include "Vector2.h"

using namespace  std;

class Collider
{
public:
	Collider();
	~Collider();

	virtual bool IsColliding(Collider& collider) = 0;
};
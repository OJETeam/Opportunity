#pragma once
#include "Collider.h"

class PolyCollider : public Collider
{
private:
	vector<Vector2> model;
public:
	PolyCollider(vector<Vector2> model);
};
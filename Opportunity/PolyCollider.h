#pragma once
#include "Collider.h"

class PolyCollider : public Collider
{
private:
	vector<Vector2> model;

	bool CheckCollision(const Collider& collider, bool& available) const override;
public:
	PolyCollider(vector<Vector2> model);
};
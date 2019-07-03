#pragma once
#include "Collider.h"

class PolyCollider : public Collider
{
private:
	vector<Vector2> transformedModel;

	bool CheckCollision(const Collider& collider, bool& available) const override;
public:
	vector<Vector2> model;

	PolyCollider(vector<Vector2> model);
	void Update(const mat4& modelMatrix) override;
	bool InCollider(Vector2 vec) const override;
};
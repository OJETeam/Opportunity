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
	static unique_ptr<PolyCollider> Cube(float sideLength, Vector2 relativePivot = Vector2(0, 0));
	static unique_ptr<PolyCollider> Rectangle(Vector2 size, Vector2 relativePivot = Vector2(0, 0));
	void Update(const mat4& modelMatrix) override;
	bool InCollider(Vector2 vec) const override;
};

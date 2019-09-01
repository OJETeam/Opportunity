#include "PolyCollider.h"
#include "Input.h"
#include "GameObject.h"
#include "Unit.h"
#include "Game.h"

PolyCollider::PolyCollider(vector<Vector2> model) : model(model)
{
}

unique_ptr<PolyCollider> PolyCollider::Cube(float sideLength, Vector2 relativePivot)
{
	Vector2 pivot = relativePivot * sideLength;
	return make_unique<PolyCollider>(vector<Vector2>({
		pivot,
		Vector2(pivot.x, pivot.y + sideLength),
		Vector2(pivot.x + sideLength, pivot.y + sideLength),
		Vector2(pivot.x + sideLength, pivot.y)
		}));
}

unique_ptr<PolyCollider> PolyCollider::Rectangle(Vector2 size, Vector2 relativePivot)
{
	Vector2 pivot = Vector2(relativePivot.x * size.x, relativePivot.y * size.y); //TODO add vector*vector multiplication to Vector2
	return make_unique<PolyCollider>(vector<Vector2>({
		pivot,
		Vector2(pivot.x, pivot.y + size.y),
		Vector2(pivot.x + size.x, pivot.y + size.y),
		Vector2(pivot.x + size.x, pivot.y)
		}));
}

void PolyCollider::Update(const mat4& modelMatrix)
{
	transformedModel.clear();
	for (Vector2& point : model)
	{
		const vec4 transformedVec = modelMatrix * vec4(point.x, point.y, 0.0f, 1.0f); //TODO optimize vec4 and mat4

		transformedModel.push_back(Vector2(transformedVec.x, transformedVec.y));
	}
}

bool PolyCollider::IsInCollider(Vector2 vec) const
{
	int lineCount = 0;

	for (int i = 0; i < transformedModel.size(); i++)
	{
		Vector2 a = i == 0 ? transformedModel[transformedModel.size() - 1] : transformedModel[i - 1];
		Vector2 b = transformedModel[i];

		if (!((vec.y >= a.y && vec.y <= b.y) || (vec.y >= b.y && vec.y <= a.y)))
			continue;

		const float x = (vec.y - a.y) * (b.x - a.x) / (b.y - a.y) + a.x;

		if (vec.x >= x)
			continue;

		lineCount++;
	}

	return lineCount % 2 != 0;
}

bool PolyCollider::CheckCollision(const Collider& collider, bool& available) const
{
	return true;
}
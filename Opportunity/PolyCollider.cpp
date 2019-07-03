#include "PolyCollider.h"
#include "Input.h"
#include "GameObject.h"
#include "Unit.h"
#include "Game.h"

PolyCollider::PolyCollider(vector<Vector2> model) : model(model)
{
}

void PolyCollider::Update(const mat4& modelMatrix)
{
	transformedModel.clear();
	for (Vector2& point : model)
	{
		const vec4 transformedVec = modelMatrix * vec4(point.x, point.y, 0.0f, 1.0f); //TODO optimize vec4 and mat4

		transformedModel.push_back(Vector2(transformedVec.x, transformedVec.y));
	}

	//TODO TEST
	if (Input::IsKeyClicked(GLFW_KEY_SLASH))
	{
		Unit* u = new Unit(Vector2(0, 0), Model(transformedModel, Color::White));
		Game::AddObject(*u);
	}
}

bool PolyCollider::InCollider(Vector2 vec) const
{
	return true;
}

bool PolyCollider::CheckCollision(const Collider& collider, bool& available) const
{
	return true;
}
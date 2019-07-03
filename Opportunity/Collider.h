#pragma once
#include <vector>
#include "Vector2.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;
using namespace glm;

class Collider
{
private:
	virtual bool CheckCollision(const Collider& collider, bool& available) const = 0;
public:
	Collider();
	~Collider();

	bool IsColliding(const Collider& collider) const;
	virtual bool InCollider(Vector2 vec) const = 0;
	virtual void Update(const mat4& modelMatrix) = 0;
};
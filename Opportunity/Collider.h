#pragma once
#include <vector>
#include <memory>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Vector2.h"

using namespace std;
using namespace glm;

class Collider
{
private:
	virtual bool CheckCollision(const Collider& collider, bool& available) const = 0;
public:
	Collider();
	virtual ~Collider();

	bool IsColliding(const Collider& collider) const;
	virtual bool InCollider(Vector2 vec) const = 0;
	virtual void Update(const mat4& modelMatrix) = 0;
};
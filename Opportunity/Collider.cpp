#include "Collider.h"

Collider::Collider()
{
}

Collider::~Collider()
{
}

bool Collider::IsColliding(const Collider& collider) const //TODO maybe not necessary
{
	bool methodAvailable = false;

	bool result = CheckCollision(collider, methodAvailable);

	if (methodAvailable)
		return result;

	result = collider.CheckCollision(*this, methodAvailable);

	if (methodAvailable)
		return result;

	throw exception("Missing collider function");
}
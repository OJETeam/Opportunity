#include "Unit.h"
#include "Time.h"

Unit::Unit(Vector2 position, Model model) : GameObject(position, model)
{
}

Unit::~Unit()
= default;

void Unit::AttachScript(AbstractScript& script, bool run)
{
	Script currentScript(script, this);
	scripts.push_back(currentScript);

	if (run)
		currentScript.Start();
}

void Unit::Update()
{
	setPosition(getPosition() + direction * (speed * Time::DeltaTime()));
	setRotation(getRotation() + rotationSpeed * Time::DeltaTime());
}

Vector2 Unit::GetDirection() const
{
	return direction;
}

void Unit::SetDirection(Vector2 direction)
{
	this->direction = direction.normalize();
}

float Unit::GetSpeed() const
{
	return speed;
}

void Unit::SetSpeed(float speed)
{
	this->speed = speed; //TODO speed limit
}

float Unit::GetRotationSpeed() const
{
	return rotationSpeed;
}

void Unit::SetRotationSpeed(float rotationSpeed)
{
	this->rotationSpeed = rotationSpeed; //TODO speed limit
}
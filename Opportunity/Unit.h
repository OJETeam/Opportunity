#pragma once
#include <vector>
#include "AbstractScript.h"
#include "Script.h"
#include "GameObject.h"

class Unit : public GameObject
{
private:
	vector<Script> scripts;
	Vector2 direction = Vector2(0, 0);
	float speed = 0;
	float rotationSpeed = 0;
public:
	Unit(Vector2 position, Model model);
	~Unit();
	void AttachScript(AbstractScript& script, bool run);
	void Update() override;
	Vector2 GetDirection() const;
	void SetDirection(Vector2 direction);
	float GetSpeed() const;
	void SetSpeed(float speed);
	float GetRotationSpeed() const;
	void SetRotationSpeed(float rotationSpeed);
};
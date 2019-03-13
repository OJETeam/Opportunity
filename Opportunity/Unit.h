#pragma once
#include <vector>
#include "Object.h"
#include "AbstractScript.h"
#include "Script.h"

class Unit : public Object
{
private:
	vector<Script> scripts;
	Vector2 direction = Vector2(0, 0);
	float speed = 0;
public:
	Unit(Vector2 position, Model model);
	~Unit();
	void AttachScript(AbstractScript& script, bool run);
	void Update() override;
	Vector2 GetDirection() const;
	void SetDirection(Vector2 direction);
	float GetSpeed() const;
	void SetSpeed(float speed);
};
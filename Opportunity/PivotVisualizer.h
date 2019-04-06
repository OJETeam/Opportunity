#pragma once
#include "GameObject.h"
class PivotVisualizer :	public GameObject
{
private:
	GameObject* object;
public:
	PivotVisualizer(GameObject* gameObject);
	~PivotVisualizer();
	void Update() override;
};
#include "PivotVisualizer.h"



PivotVisualizer::PivotVisualizer(GameObject* gameObject) : GameObject(gameObject->getPosition(), Model::Cube(10, Color(1, 1, 0), Vector2(0.5, 0.5))), object(gameObject)
{
}


PivotVisualizer::~PivotVisualizer()
{
}

void PivotVisualizer::Update()
{
	position = object->getPosition();
}
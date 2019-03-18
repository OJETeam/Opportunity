#pragma once
#include <vector>

#include "Vector2.h"
#include "Color.h"

using namespace std;

class Model
{
public:
	/*enum class Pivot
	{
		BOTTOM_LEFT, TOP_LEFT, TOP_RIGHT, BOTTOM_RIGHT, CENTER
	};*/ //TODO Maybe implement later

	vector<Vector2> model;
	Color color;
	Vector2 pivot = Vector2(0, 0);

	Model(vector<Vector2> model, Color color);
	~Model();

	static Model Cube(float sideLength, Color color, Vector2 relativePivot);
};
#pragma once
#include <vector>

#include "Vector2.h"
#include "Color.h"

using namespace std;

class Model
{
public:
	vector<Vector2> model;
	Color color;

	Model(vector<Vector2> model);
	~Model();
};
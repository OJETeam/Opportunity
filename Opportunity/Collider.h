#pragma once
#include <vector>
#include "Vector2.h"

using namespace  std;

class Collider
{
public:
	vector<Vector2> model;

	Collider();
	~Collider();
};
#include "Model.h"
#include <iostream>

Model::Model(vector<Vector2> model, Color color) : model(vector<Vector2>(model)), color(color)
{
}

Model::~Model()
{
}

Model Model::Cube(float sideLength, Color color, Vector2 relativePivot = Vector2(0, 0))
{
	Model model = Model({ Vector2(0, 0), Vector2(sideLength, 0), Vector2(0, sideLength), Vector2(0, sideLength), Vector2(sideLength, sideLength), Vector2(sideLength, 0) }, color);
	model.pivot = relativePivot * sideLength;
	return model;
}
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
	Model model = Model({ Vector2(0, 0), Vector2(sideLength, 0), Vector2(0, sideLength), Vector2(0, sideLength), Vector2(sideLength, sideLength), Vector2(sideLength, 0) }, color); //TODO triangle_strip
	model.pivot = relativePivot * sideLength;
	return model;
}

Model Model::Rectangle(Vector2 size, Color color, Vector2 relativePivot)
{
	Model model = Model({ Vector2(0, 0), Vector2(size.x, 0), Vector2(0, size.y), Vector2(0, size.y), Vector2(size.x, size.y), Vector2(size.x, 0) }, color);
	model.pivot = Vector2(size.x * relativePivot.x, size.y * relativePivot.y);
	return model;
}
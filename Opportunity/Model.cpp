#include "Model.h"
#include <iostream>

Model::Model(vector<Vector2> model, Color color) : model(vector<Vector2>(model)), color(color)
{
	//if (color.a == 0)
		cout << "i am constructed" << endl;
}

Model::~Model()
{
	//if (color.a == 0)
		cout << "i am deleted" << endl;
}

Model Model::Cube(float sideLength, Color color)
{
	return Model({ Vector2(0, 0), Vector2(sideLength, 0), Vector2(0, sideLength), Vector2(0, sideLength), Vector2(sideLength, sideLength), Vector2(sideLength, 0) }, color);
}
#include "Object.h"

Object::Object(Vector2 position, Model model) : model(model), position(position), shader("vertex.txt", "fragment.txt", "")
{
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	UpdateModel();
}

void Object::Render()
{
	
}

void Object::UpdateModel()
{
	if (model.model.size() == 0) return;

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vector2), nullptr);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vector2) * model.model.size(), model.model.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Object::OnCreate()
{
}

void Object::OnDelete()
{
}
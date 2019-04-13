#include "Object.h"
#include "Window.h"
#include "Camera.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Game.h"

Object::Object(Vector2 position, Model model) : model(model), position(position), shader("vertex.vert", "fragment.frag", "")
{
	parent = nullptr;
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	UpdateModel();
}

void Object::UpdateModel()
{
	if (model.model.empty())
		return;

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

float Object::getX() const
{
	return position.x;
}

float Object::getY() const
{
	return position.y;
}

Vector2 Object::getPosition() const
{
	return position;
}

void Object::setPosition(Vector2 position)
{
	if (!children.empty())
	{
		const Vector2 diff = position - this->position;

		for (int i = 0; i < children.size(); i++)
			children[i]->setPosition(children[i]->position + diff);
	}

	this->position = position;
}

Vector2 Object::getSize() const
{
	return size;
}

void Object::setSize(Vector2 scale)
{
	//TODO parent
	this->size = scale;
}

float Object::getRotation() const
{
	return rotation;
}

void Object::setRotation(float rotation)
{
	if (!children.empty())
	{
		const float diff = rotation - this->rotation;

		for (int i = 0; i < children.size(); i++)
		{
			Object& child = *children[i];
			const Vector2 normalizedChildPos = child.position - position;
			const float childRotation = rotation;
			child.position.x = (normalizedChildPos.x * cosf(diff) - normalizedChildPos.y * sinf(diff)) + position.x;
			child.position.y = (normalizedChildPos.x * sinf(diff) + normalizedChildPos.y * cosf(diff)) + position.y;
			child.setRotation(childRotation);
		}
	}

	this->rotation = rotation;
}

unsigned int Object::getDepth() const
{
	return depth;
}

void Object::setDepth(unsigned int depth)
{
	this->depth = depth;
	Game::UpdateDepth();
}

void Object::OnCreate()
{
}

void Object::OnDelete()
{
}
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Game.h"
#include "Object.h"
#include "Window.h"
#include "Camera.h"

Object::Object(Vector2 position, Model model) : position(position), model(model), collider(nullptr), shader("vertex.vert", "fragment.frag", "")
{
	parent = nullptr;
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	UpdateModel();
	UpdateTransform();
}

Object::~Object()
{
}

void Object::UpdateModel()
{
	if (model.model.empty())
		return;

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vector2), nullptr);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);

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

	UpdateTransform();
}

Vector2 Object::getSize() const
{
	return scale;
}

void Object::setSize(Vector2 scale)
{
	if (!children.empty())
	{
		const Vector2 diff = scale - this->scale;

		for (int i = 0; i < children.size(); i++)
		{
			Object& child = *children[i];

			child.setPosition(position + diff * (child.position - position));
			child.setSize(child.scale + diff);
		}
	}

	this->scale = scale;

	UpdateTransform();
}

float Object::getRotation() const
{
	return rotation;
}

void Object::setRotation(float rotation) //TODO switch from delta rotation to absolute rotation
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

	UpdateTransform();
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

void Object::UpdateTransform()
{
	modelMatrix = glm::mat4(1.0f);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(position.x, position.y, 0));
	modelMatrix = glm::scale(modelMatrix, glm::vec3(scale.x, scale.y, 1.0f));
	modelMatrix = glm::rotate(modelMatrix, rotation, glm::vec3(0, 0, 1));
	modelMatrix = glm::translate(modelMatrix, glm::vec3(-model.pivot.x, -model.pivot.y, 0));

	if (collider)
		collider->Update(modelMatrix);
}

void Object::OnCreate()
{
}

void Object::OnDelete()
{
}

void Object::OnMouseEnter()
{
}

void Object::OnMouseOver()
{
}

void Object::OnMouseExit()
{
}

void Object::OnMousePressed(unsigned int mouseButton)
{
}

void Object::OnMouseDrag(unsigned int mouseButton)
{
}

void Object::OnMouseReleased(unsigned int mouseButton)
{
}

void Object::OnMouseClicked(unsigned int mouseButton)
{
}

void Object::OnCollisionEnter(Object& obj)
{
}

void Object::OnCollisionExit(Object& obj)
{
}

void Object::OnCollisionStay(Object& obj)
{
}
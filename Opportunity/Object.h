#pragma once

#include <glad/glad.h>

#include "Model.h"
#include "Vector2.h"
#include "Texture.h"
#include "ShaderProgram.h"

class Object
{
protected:
	unsigned int vao, vbo;

public:
	Model model;
	Vector2 position;
	ShaderProgram shader;

	Object(Vector2 position, Model model);

	void UpdateModel();

	void Render();
	void Update();

	/*bool isColliding(Object& obj) const;
	virtual void onCollisionEnter(Object& obj);
	virtual void onCollisionExit(Object& obj);
	virtual void onCollisionStay(Object& obj);
	virtual void onDelete();
	Vector2 getPosition() const;
	Vector2 getSize() const;
	float getX() const;
	float getY() const;
	void setPosition(Vector2 newPosition);*/
};
#pragma once

#include "Model.h"
#include "Vector2.h"
#include "Texture.h"
#include "ShaderProgram.h"

class Object
{
protected:
	Object* parent;
	unsigned int vao, vbo;
public:
	Model model;
	Vector2 position;
	Vector2 scale = Vector2(1.0f, 1.0f);
	float rotation = 0;
	ShaderProgram shader;
	Vector2 parentPivot;

	Object(Vector2 position, Model model);

	void UpdateModel();

	virtual void Render() = 0;
	virtual void Update() = 0;
	virtual void OnCreate();
	virtual void OnDelete();

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
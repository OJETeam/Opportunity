#pragma once

#include "Model.h"
#include "Vector2.h"
#include "Texture.h"
#include "ShaderProgram.h"

class Object
{
protected:
	Vector2 position; //TODO maybe private (position, scale, rotation)
	Vector2 scale = Vector2(1.0f, 1.0f);
	float rotation = 0;
	Object* parent;
	vector<Object*> children; //TODO maybe not optimal
	unsigned int vao, vbo;
public:
	Model model;
	ShaderProgram shader;
	Vector2 parentPivot;

	Object(Vector2 position, Model model);

	void UpdateModel();
	float getX() const;
	float getY() const;
	Vector2 getPosition() const;
	void setPosition(Vector2 position);
	Vector2 getSize() const;
	void setSize(Vector2 scale);
	float getRotation() const;
	void setRotation(float rotation);

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
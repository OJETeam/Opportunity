#pragma once

#include "Model.h"
#include "Vector2.h"
#include "Texture.h"
#include "ShaderProgram.h"
#include "Collider.h"

class Object
{
protected:
	Vector2 position; //TODO maybe private (position, scale, rotation)
	unsigned int depth = 0;
	Vector2 scale = Vector2(1.0f, 1.0f);
	float rotation = 0;
	Object* parent = nullptr;
	vector<Object*> children;
	unsigned int vao, vbo;
public:
	Model model;
	Collider* collider;
	ShaderProgram shader;
	Vector2 parentPivot;
	bool visible = true;

	Object(Vector2 position, Model model = Model()); //TODO probably remove Model from constructor

	void UpdateModel();
	float getX() const;
	float getY() const;
	Vector2 getPosition() const;
	void setPosition(Vector2 position); //TODO maybe add addPosition function
	Vector2 getSize() const;
	void setSize(Vector2 scale);
	float getRotation() const;
	void setRotation(float rotation);
	unsigned int getDepth() const;
	void setDepth(unsigned int depth);

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

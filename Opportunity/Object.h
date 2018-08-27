#pragma once
#include "Model.h"
#include "Vector2.h"
#include "Texture.h"

class Object
{
public:
	Model model;

	Object(Vector2 position);

	virtual void update() = 0;

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
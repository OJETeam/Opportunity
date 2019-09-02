#pragma once
#include <memory>
#include "Model.h"
#include "Vector2.h"
#include "Texture.h"
#include "ShaderProgram.h"
#include "Collider.h"

using namespace std;

class Object
{
protected:
	Vector2 position;
	Vector2 scale = Vector2(1.0f, 1.0f);
	float rotation = 0;
	unsigned int depth = 0;
	Object* parent = nullptr;
	vector<Object*> children;
	unsigned int vao, vbo;
	mat4 modelMatrix;

	void UpdateTransform(); //TODO Possibly bad code
public:
	Model model;
	unique_ptr<Collider> collider; //TODO this is why i should switch to component system
	ShaderProgram shader;
	Vector2 parentPivot; //TODO finish
	bool visible = true;

	Object(Vector2 position, Model model = Model()); //TODO probably remove Model from constructor
	virtual ~Object();

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

	virtual void OnMouseEnter();
	virtual void OnMouseOver();
	virtual void OnMouseExit();
	virtual void OnMousePressed(unsigned int mouseButton);
	virtual void OnMouseDrag(unsigned int mouseButton);
	virtual void OnMouseReleased(unsigned int mouseButton);
	virtual void OnMouseClicked(unsigned int mouseButton);

	virtual void OnCollisionEnter(Object& obj);
	virtual void OnCollisionExit(Object& obj);
	virtual void OnCollisionStay(Object& obj);
};
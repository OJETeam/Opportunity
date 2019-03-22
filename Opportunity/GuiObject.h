#pragma once
#include "Object.h"

typedef void(*ClickEvent)();

class GuiObject : public Object
{
private:
	vector<ClickEvent> events;
public:
	GuiObject* parent;
	Vector2 parentPivot;
	bool clickable;
	GuiObject(Vector2 position, Model model);
	void Render() override;
	void SubscribeClick(ClickEvent response);
	void UnsubscribeClick(ClickEvent response);
};
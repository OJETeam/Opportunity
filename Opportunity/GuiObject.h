#pragma once
#include "Object.h"

typedef void(*ClickEvent)();

class GuiObject : public Object
{
private:
	vector<ClickEvent> events;
public:
	Vector2 parentPivot;
	bool clickable;
	GuiObject(Vector2 relativePosition, Model model);
	void Render() override;
	void SubscribeClick(ClickEvent response);
	void UnsubscribeClick(ClickEvent response);
};
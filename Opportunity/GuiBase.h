#pragma once
#include "Object.h"

typedef void(*ClickEvent)();

class GuiBase : Object
{
private:
	vector<ClickEvent> events;
public:
	GuiBase* parent;
	Vector2 parentPivot;
	bool clickable;
	GuiBase(Vector2 position, Model model);
	~GuiBase();
	void Update() override {}
	void SubscribeClick(ClickEvent response);
	void UnsubscribeClick(ClickEvent response);
};
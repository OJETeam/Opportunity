#pragma once
#include "GuiObject.h"

class GuiButton : public GuiObject
{
public:
	GuiButton(Vector2 position, Vector2 size, Color color, Vector2 relativePivot);
	void Update() override;
};
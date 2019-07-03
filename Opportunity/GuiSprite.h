#pragma once
#include "GuiObject.h"

class GuiSprite : public GuiObject
{
public:
	GuiSprite(Vector2 position, Vector2 size, Color color, Vector2 relativePivot);
	void Update() override;
};
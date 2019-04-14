#pragma once
#include "GuiObject.h"

class GuiText : public GuiObject
{
private:
	string text;
public:
	GuiText(string text, Vector2 position, Vector2 size, Color color, Vector2 relativePivot);
	string getText();
	void setText(string text);
};
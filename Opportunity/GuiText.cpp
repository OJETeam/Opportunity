#include "GuiText.h"

GuiText::GuiText(string text, Vector2 position, Vector2 size, Color color, Vector2 relativePivot) : GuiObject(position, Model::Rectangle(size, color, relativePivot))
{
	setText(text);
}

string GuiText::getText()
{
	return text;
}

void GuiText::setText(string text)
{
	this->text = text;
}
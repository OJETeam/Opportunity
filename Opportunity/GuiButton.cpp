#include "GuiButton.h"

GuiButton::GuiButton(Vector2 relativePosition, Vector2 size, Color color, Vector2 relativePivot) : GuiObject(relativePosition, Model::Rectangle(size, color, relativePivot))
{

}

void GuiButton::Update()
{
}
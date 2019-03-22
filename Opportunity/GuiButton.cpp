#include "GuiButton.h"

GuiButton::GuiButton(Vector2 position, Vector2 size, Color color, Vector2 relativePivot) : GuiObject(position, Model::Rectangle(size, color, relativePivot))
{

}

void GuiButton::Update()
{
}
#include "GuiSprite.h"

GuiSprite::GuiSprite(Vector2 position, Vector2 size, Color color, Vector2 relativePivot) : GuiObject(position, Model::Rectangle(size, color, relativePivot))
{

}
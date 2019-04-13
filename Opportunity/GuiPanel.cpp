#include "GuiPanel.h"

GuiPanel::GuiPanel()
{
}

void GuiPanel::SetVisible(bool visible)
{
	for (GuiObject* element : elements)
	{
		element->visible = visible;
	}
}

void GuiPanel::Show()
{
	SetVisible(true);
}

void GuiPanel::Hide()
{
	SetVisible(false);
}
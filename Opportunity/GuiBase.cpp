#include "GuiBase.h"

GuiBase::GuiBase(Vector2 position, Model model) : Object(position, model)
{

}

GuiBase::~GuiBase()
{

}

void GuiBase::SubscribeClick(ClickEvent response)
{
	events.push_back(response);
}

void GuiBase::UnsubscribeClick(ClickEvent response)
{
	for (auto i = events.begin(); i != events.end(); ++i)
	{
		if (*i == response)
		{
			events.erase(i);
			return;
		}
	}
}
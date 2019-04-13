#pragma once
#include <vector>
#include "GuiObject.h"

using namespace std;

class GuiPanel
{
protected:
	std::vector<GuiObject*> elements;
public:
	GuiPanel();
	void SetVisible(bool visible);
	void Show();
	void Hide();
};
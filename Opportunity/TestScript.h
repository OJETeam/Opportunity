#pragma once
#include <iostream>
#include "IGameScript.h"

using namespace std;

class TestScript : public IGameScript
{
public:
	TestScript();
	void Start() override;
	void Update() override;
	void Stop() override;
};
#pragma once

class IGameScript
{
public:
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Stop() = 0;
};
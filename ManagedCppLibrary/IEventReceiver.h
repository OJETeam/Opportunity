#pragma once
public ref class IEventReceiver
{
public:
	virtual void Start() = 0;
	virtual void Update() = 0;
	IEventReceiver();
};
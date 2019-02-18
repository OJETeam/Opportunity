#pragma once

namespace ScriptManager
{
	public interface class IEventReceiver
	{
	public:
		virtual void Start() = 0;
		virtual void Update() = 0;
	};
}
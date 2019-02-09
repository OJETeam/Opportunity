#pragma once

namespace Engine
{
	public ref class Script abstract
	{
	internal:
		void* unit;
	public:
		Script();
		virtual void Start() = 0;
		virtual void Update() = 0;
	};
}
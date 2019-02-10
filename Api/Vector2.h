#pragma once

namespace Engine
{
	public value class Vector2
	{
	public:
		float x, y;

		Vector2(float x, float y);
		Vector2 operator+(Vector2 second);
		Vector2 operator-(Vector2 second);
		Vector2 operator*(float second);
		Vector2 operator/(float second);
		float length();
		Vector2 normalize(float length);
		float dot(Vector2 second);
		Vector2 lookAt(Vector2 direction);
	};
}
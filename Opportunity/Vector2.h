#pragma once

//TODO make template and typedef Vector2<float> Vector2

class Vector2
{
public:
	float x, y;

	Vector2();

	Vector2(float x, float y) : x(x), y(y) {}
	Vector2 operator+(Vector2 second) const;
	Vector2& operator+=(Vector2 second);
	Vector2 operator-(Vector2 second) const;
	Vector2& operator-=(Vector2 second);
	Vector2 operator*(float second) const;
	Vector2 operator/(float second) const;
	float length() const;
	Vector2 normalize(float length = 1) const;
	float dot(Vector2 second) const;
	Vector2 lookAt(Vector2 direction) const;
};
#include <valarray>
#include "Vector2.h"

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2 Vector2::operator+(Vector2 second) const
{
	return Vector2(x + second.x, y + second.y);
}

Vector2& Vector2::operator+=(Vector2 second)
{
	x += second.x;
	y += second.y;
	return *this;
}

Vector2 Vector2::operator-(Vector2 second) const
{
	return Vector2(x - second.x, y - second.y);
}

Vector2& Vector2::operator-=(Vector2 second)
{
	x -= second.x;
	y -= second.y;
	return *this;
}

Vector2 Vector2::operator*(float second) const
{
	return Vector2(x * second, y * second);
}

Vector2 Vector2::operator/(float second) const
{
	return Vector2(x / second, y / second);
}

float Vector2::length() const
{
	return std::sqrt(x * x + y * y);
}

Vector2 Vector2::normalize(float length) const
{
	float vecLength = this->length();
	if (vecLength == 0)
		return Vector2(0, 0);

	return *this * (length / vecLength);
}

float Vector2::dot(Vector2 second) const
{
	return x * second.x + y * second.y;
}

Vector2 Vector2::lookAt(Vector2 direction) const
{
	return (direction - *this).normalize();
}
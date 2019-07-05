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

bool Vector2::operator==(const Vector2& other) const
{
	return x == other.x && y == other.y;
}

bool Vector2::operator!=(const Vector2& other) const
{
	return x != other.x || y != other.y;
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

std::string Vector2::to_string() const
{
	return "(" + std::to_string(x) + "; " + std::to_string(y) + ")";
}
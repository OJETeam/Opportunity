#include <valarray>
#include "Vector2.h"

using namespace Engine;

Vector2::Vector2(float x, float y) : x(x), y(y)
{

}

Vector2 Vector2::operator+(Vector2 second)
{
	return Vector2(x + second.x, y + second.y);
}

Vector2 Vector2::operator-(Vector2 second)
{
	return Vector2(x - second.x, y - second.y);
}

Vector2 Vector2::operator*(float second)
{
	return Vector2(x * second, y * second);
}

Vector2 Vector2::operator/(float second)
{
	return Vector2(x / second, y / second);
}

float Vector2::length()
{
	return std::sqrt(x * x + y * y);
}

Vector2 Vector2::normalize(float length)
{
	return *this * (length / this->length());
}

float Vector2::dot(Vector2 second)
{
	return x * second.x + y * second.y;
}

Vector2 Vector2::lookAt(Vector2 direction)
{
	return (direction - *this).normalize(1);
}
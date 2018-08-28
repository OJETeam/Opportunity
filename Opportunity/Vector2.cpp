#include "Vector2.h"
#include <valarray>

Vector2::Vector2() 
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float x, float y) : x(x), y(y)
{

}

Vector2 Vector2::operator+(Vector2 second) const
{
	return Vector2(x + second.x, y + second.y);
}

Vector2 Vector2::operator-(Vector2 second) const
{
	return Vector2(x - second.x, y - second.y);
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
	return *this * (length / this->length());
}

float Vector2::dot(Vector2 second) const
{
	return x * second.x + y * second.y;
}

Vector2 Vector2::lookAt(Vector2 direction) const
{
	return (direction - *this).normalize();
}
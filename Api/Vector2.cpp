#include <valarray>
#include "Vector2.h"

using namespace Engine;

Engine::Vector2::Vector2(const ::Vector2& vec)
{
	x = vec.x;
	y = vec.y;
}

Engine::Vector2::Vector2(float x, float y) : x(x), y(y)
{

}

Engine::Vector2 Engine::Vector2::operator+(Vector2 second)
{
	return Vector2(x + second.x, y + second.y);
}

Engine::Vector2 Engine::Vector2::operator-(Vector2 second)
{
	return Vector2(x - second.x, y - second.y);
}

Engine::Vector2 Engine::Vector2::operator*(float second)
{
	return Vector2(x * second, y * second);
}

Engine::Vector2 Engine::Vector2::operator/(float second)
{
	return Vector2(x / second, y / second);
}

Engine::Vector2::operator ::Vector2()
{
	return ::Vector2(x, y);
}

float Engine::Vector2::length()
{
	return std::sqrt(x * x + y * y);
}

Engine::Vector2 Engine::Vector2::normalize(float length)
{
	return *this * (length / this->length());
}

float Engine::Vector2::dot(Vector2 second)
{
	return x * second.x + y * second.y;
}

Engine::Vector2 Engine::Vector2::lookAt(Vector2 direction)
{
	return (direction - *this).normalize(1);
}
#include "Color.h"

const Color Color::Red = Color(1, 0, 0);
const Color Color::Green = Color(0, 1, 0);
const Color Color::Blue = Color(0, 0, 1);
const Color Color::White = Color(1, 1, 1);
const Color Color::Black = Color(0, 0, 0);
const Color Color::Transparent = Color(0, 0, 0, 0);

Color::Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a)
{	
}

Color Color::operator+(const Color second) const
{
	return Color(r + second.r, g + second.g, b + second.b, a + second.a);
}

Color Color::operator-(const Color second) const
{
	return Color(r - second.r, g - second.g, b - second.b, a - second.a);
}

Color Color::operator*(float scalar) const
{
	return Color(r * scalar, g * scalar, b * scalar, a * scalar);
}

Color Color::operator/(float scalar) const
{
	return Color(r / scalar, g / scalar, b / scalar, a / scalar);
}
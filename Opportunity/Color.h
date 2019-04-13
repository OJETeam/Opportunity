#pragma once
struct Color
{
	float r;
	float g;
	float b;
	float a;

	static const Color Red;
	static const Color Green;
	static const Color Blue;
	static const Color White;
	static const Color Black;
	static const Color Transparent;
	Color();
	Color(float r, float g, float b, float a = 1);
	Color operator+(const Color second) const;
	Color operator-(const Color second) const;
	Color operator*(float scalar) const;
	Color operator/(float scalar) const;
};
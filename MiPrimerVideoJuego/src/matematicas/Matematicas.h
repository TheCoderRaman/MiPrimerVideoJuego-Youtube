#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

#include <SFML/System/Vector2.hpp>

constexpr auto PI = 3.14159265f;

float Rad2De(float radianes)
{
	return 180.f * radianes / PI;
}

float magnitud(const sf::Vector2f& vector)
{
	return std::sqrtf(vector.x * vector.x + vector.y * vector.y);
}

sf::Vector2f normalizar(const sf::Vector2f& vector)
{
	float m = magnitud(vector);

	if (m == 0)
		return sf::Vector2f(0.f, 0.f);

	return sf::Vector2f(vector.x / m, vector.y / m);
}

float miraA(const sf::Vector2f& posicion, const sf::Vector2f& objetivo)
{
	sf::Vector2f dir = objetivo - posicion;
	return Rad2De(atan2(dir.y, dir.x)) + 90.f;
}
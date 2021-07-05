#include "utility.h"

float Length(sf::Vector2f v)
{
	return (float)sqrt((v.x * v.x) + (v.y * v.y));
}

float Distance(sf::Vector2f start, sf::Vector2f end)
{
	sf::Vector2f v = start - end;
	return Length(v);
}

void Normalise(sf::Vector2f& normalise)
{
	float l = Length(normalise);
	if (l > 0.0f)
	{
		normalise.x *= 1.0f / l;
		normalise.y *= 1.0f / l;
	}
}

// Truncating is what happens when we look at a number with a decimal component (such as 10.5) and take only the whole number of it, effectively destroying the decimal part.
// No rounding occurs, which means that even if the number would be rounded up to the next number (such as 10.75 being rounded up to 11), we still only take the whole number component
void Truncate(sf::Vector2f& v, float max)
{
	if (Length(v) > max)
	{
		Normalise(v);
		v *= max;
	}
}
#include "MathHelper.h"
#include <cmath>

float MathHelper::MagnitudeSquared(const Vector2& v)
{
	return v.x * v.x + v.y * v.y;
}

float MathHelper::MagnitudeSquared(const Vector3& v)
{
	return 0.0f;
}

float MathHelper::Magnitude(const Vector2& v)
{
	return sqrt(MagnitudeSquared(v));
}

float MathHelper::Magnitude(const Vector3& v)
{
	return 0.0f;
}

Vector2 MathHelper::Normalize(const Vector2& v)
{
	return v / Magnitude(v);
}

Vector3 MathHelper::Normalize(const Vector3& v)
{
	return Vector3();
}

float MathHelper::Dot(const Vector2& a, const Vector2& b)
{
	return (a.x * b.x) + (a.y * b.y);
}

float MathHelper::Dot(const Vector3& a, const Vector3& b)
{
	return 0.0f;
}

Vector3 MathHelper::Cross(const Vector3& a, const Vector3& b)
{
	return Vector3();
}
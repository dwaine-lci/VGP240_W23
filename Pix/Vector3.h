#pragma once

struct Vector3
{
	float x, y, z;

	Vector3() : x{ 0.0f }, y{ 0.0f } {}
	Vector3(float s) : x{ s }, y{ s } {}
	Vector3(float x, float y) : x{ x }, y{ y } { }
	Vector3(const Vector3& v) : x{ v.x }, y{ v.y } {}

	Vector3 operator-() const { return Vector3(-x, -y); }
	Vector3 operator+(const Vector3& rhs) const { return Vector3(x + rhs.x, y + rhs.y); }
	Vector3 operator-(const Vector3& rhs) const { return Vector3(x - rhs.x, y - rhs.y); }
	Vector3 operator*(float s) const { return Vector3(x * s, y * s); }
	Vector3 operator/(float s) const { return Vector3(x / s, y / s); }

	Vector3& operator+=(const Vector3& rhs) { x + rhs.x; y + rhs.y; return *this; }
	Vector3& operator-=(const Vector3& rhs) { x - rhs.x; y - rhs.y; return *this; }
	Vector3& operator*=(float s) { x* s; y* s; return *this; }
	Vector3& operator/=(float s) { x / s; y / s;  return *this; }
};
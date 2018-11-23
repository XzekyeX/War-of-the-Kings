#include "Vec2.h"
/**
*
* @author Mikko Tekoniemi
*
*/
Vec2::Vec2() {
	x = 0.0f;
	y = 0.0f;
}
Vec2::Vec2(const float& x, const float& y) {
	this->y = y;
	this->x = x;
}
Vec2& Vec2::add(const Vec2& other) {
	x += other.x;
	y += other.y;
	return *this;
}
Vec2& Vec2::subtract(const Vec2& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}
Vec2& Vec2::multiply(const Vec2& other) {
	x *= other.x;
	y *= other.y;
	return *this;
}
Vec2& Vec2::divide(const Vec2& other) {
	x /= other.x;
	y /= other.y;
	return *this;
}
Vec2 operator+(Vec2 left, const Vec2& right) {
	return left.add(right);
}

float Vec2::distance(const Vec2& other) const {
	float a = x - other.x;
	float b = y - other.y;
	return sqrt(a * a + b * b);
}

float Vec2::dot(const Vec2& other) const {
	return x * other.x + y * other.y;
}

float Vec2::magnitude() const {
	return sqrt(x * x + y * y);
}

Vec2 Vec2::normalize() const {
	float length = magnitude();
	return Vec2(x / length, y / length);
}

Vec2 operator-(Vec2 left, const Vec2&right) {
	return left.subtract(right);
}

Vec2 operator*(Vec2 left, const Vec2&right) {
	return left.multiply(right);
}

Vec2 operator/(Vec2 left, const Vec2&right) {
	return left.divide(right);
}

bool Vec2::operator==(const Vec2& other) {
	return x == other.x && y == other.y;
}

bool Vec2::operator!=(const Vec2& other) {
	return !(*this == other);
}

Vec2& Vec2::operator+=(const Vec2& other) {
	return add(other);
}

Vec2& Vec2::operator-=(const Vec2& other) {
	return subtract(other);
}

Vec2& Vec2::operator*=(const Vec2& other) {
	return multiply(other);
}

Vec2& Vec2::operator/=(const Vec2& other) {
	return divide(other);
}

std::ostream& operator<<(std::ostream& stream, const Vec2& vector) {
	stream << "Vec2(" << vector.x << ", " << vector.y << ")";
	return stream;
}
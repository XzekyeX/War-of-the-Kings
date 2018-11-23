#include "Vec4.h"

/**
*
* @author Mikko Tekoniemi
*
*/

Vec4::Vec4(const unsigned int& color) {
	//int r = (int)(color.x * 255.0f);
	//int g = (int)(color.y * 255.0f);
	//int b = (int)(color.w * 255.0f);
	//int a = (int)(color.h * 255.0f);
	//this->color = (a << 24 | b << 16 | g << 8 | r);
	this->x = color >> 16 & 0xFF; // red
	this->y = color >> 8 & 0xFF; // green
	this->z = color >> 0 & 0xFF; // blue
	this->w = color >> 24 & 0xFF; // alpha
}

Vec4::Vec4(const float& x, const float& y, const float& z, const float& w) {
	this->y = y;
	this->x = x;
	this->z = z;
	this->w = w;
}

Vec4& Vec4::add(const Vec4& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	return *this;
}

Vec4& Vec4::subtract(const Vec4& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
	return *this;
}

Vec4& Vec4::multiply(const Vec4& other) {
	x *= other.x;
	y *= other.y;
	z *= other.z;
	w *= other.w;
	return *this;
}

Vec4& Vec4::divide(const Vec4& other) {
	x /= other.x;
	y /= other.y;
	z /= other.z;
	w /= other.w;
	return *this;
}

Vec4 operator+(Vec4 left, const Vec4& right) {
	return left.add(right);
}

Vec4 operator-(Vec4 left, const Vec4&right) {
	return left.subtract(right);
}

Vec4 operator*(Vec4 left, const Vec4&right) {
	return left.multiply(right);
}

Vec4 operator/(Vec4 left, const Vec4&right) {
	return left.divide(right);
}

bool Vec4::operator==(const Vec4& other) {
	return x == other.x && y == other.y && z == other.z && w == other.w;
}

bool Vec4::operator!=(const Vec4& other) {
	return !(*this == other);
}

Vec4& Vec4::operator+=(const Vec4& other) {
	return add(other);
}

Vec4& Vec4::operator-=(const Vec4& other) {
	return subtract(other);
}

Vec4& Vec4::operator*=(const Vec4& other) {
	return multiply(other);
}

Vec4& Vec4::operator/=(const Vec4& other) {
	return divide(other);
}

float Vec4::dot(const Vec4 & other) {
	return x * other.x + y * other.y + z * other.z + w * other.w;
}

std::ostream& operator<<(std::ostream& stream, const Vec4& vector) {
	stream << "Vec4(";
	stream << std::fixed << std::setprecision(2) << vector.x << ", ";
	stream << std::fixed << std::setprecision(2) << vector.y << ", ";
	stream << std::fixed << std::setprecision(2) << vector.z << ", ";
	stream << std::fixed << std::setprecision(2) << vector.w << ")";
	return stream;
}
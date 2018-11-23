#include "Quaternion.h"

/**
*
* @author Mikko Tekoniemi
*
*/

Quaternion::Quaternion(const Quaternion & q) {
	this->x = q.x;
	this->y = q.y;
	this->z = q.z;
	this->w = q.w;
}

Quaternion::Quaternion(const float & x, const float & y, const float & z, const float & w) {
	this->y = y;
	this->x = x;
	this->z = z;
	this->w = w;
}

Quaternion::Quaternion(const Vec3 & xyz, float w) {
	this->x = xyz.x;
	this->y = xyz.y;
	this->z = xyz.z;
	this->w = w;
}

Quaternion::Quaternion(const Vec4 & v) {
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	this->w = v.w;
}

Quaternion::Quaternion(float scalar) {
	this->x = scalar;
	this->y = scalar;
	this->z = scalar;
	this->w = scalar;
}

Quaternion& Quaternion::add(const Quaternion& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	return *this;
}

Quaternion& Quaternion::subtract(const Quaternion& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
	return *this;
}

Quaternion& Quaternion::multiply(const Quaternion& other) {
	x *= other.x;
	y *= other.y;
	z *= other.z;
	w *= other.w;
	return *this;
}

Quaternion& Quaternion::divide(const Quaternion& other) {
	x /= other.x;
	y /= other.y;
	z /= other.z;
	w /= other.w;
	return *this;
}
Quaternion& Quaternion::add(float scalar) {
	x += scalar;
	y += scalar;
	z += scalar;
	w += scalar;
	return *this;
}

Quaternion& Quaternion::subtract(float scalar) {
	x -= scalar;
	y -= scalar;
	z -= scalar;
	w -= scalar;
	return *this;
}

Quaternion& Quaternion::multiply(float scalar) {
	x *= scalar;
	y *= scalar;
	z *= scalar;
	w *= scalar;
	return *this;
}

Quaternion& Quaternion::divide(float scalar) {
	x /= scalar;
	y /= scalar;
	z /= scalar;
	w /= scalar;
	return *this;
}

Quaternion operator+(Quaternion left, const Quaternion& right) {
	return left.add(right);
}

Quaternion operator-(Quaternion left, const Quaternion&right) {
	return left.subtract(right);
}

Quaternion operator*(Quaternion left, const Quaternion&right) {
	return left.multiply(right);
}

Quaternion operator/(Quaternion left, const Quaternion&right) {
	return left.divide(right);
}

bool Quaternion::operator==(const Quaternion& other) {
	return x == other.x && y == other.y && z == other.z && w == other.w;
}

bool Quaternion::operator!=(const Quaternion& other) {
	return !(*this == other);
}

Quaternion& Quaternion::operator+=(const Quaternion& other) {
	return add(other);
}

Quaternion& Quaternion::operator-=(const Quaternion& other) {
	return subtract(other);
}

Quaternion& Quaternion::operator*=(const Quaternion& other) {
	return multiply(other);
}

Quaternion& Quaternion::operator/=(const Quaternion& other) {
	return divide(other);
}

float Quaternion::dot(const Quaternion& other) const {
	return x * other.x + y * other.y + z * other.z + w * other.w;
}

float Quaternion::length(const Quaternion& other) const {
	return sqrt(dot(other));
}


Quaternion Quaternion::conjugate() {
	return Quaternion(-x, -y, -z, w);
}

Vec3 Quaternion::getAxis() const {
	float x = 1.0f - w * w;
	if(x < 0.0000001f) return Vec3(1.0f, 0.0f, 0.0f);
	return getXYZ() / (x * x);
}

Vec3 Quaternion::getXYZ() const {
	return Vec3(x, y, z);
}

Vec3 Quaternion::toEulerAngles() {
	return Vec3(atan2(2 * x * w - 2 * y * z, 1 - 2 * x * x - 2 * z * z), atan2(2 * y * w - 2 * x * z, 1 - 2 * y * y - 2 * z * z), asin(2 * x * y + 2 * z * w));
}

Quaternion Quaternion::identity() {
	return Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
}

Quaternion Quaternion::fromEulerAngles(const Vec3 & angles) {
	Quaternion pitch(Vec3(1.0, 0.0, 0.0), angles.x);
	Quaternion yaw(Vec3(0.0, 1.0, 0.0), angles.y);
	Quaternion roll(Vec3(0.0, 0.0, 1.0), angles.z);
	return pitch * yaw * roll;
}

Vec3 Quaternion::rotate(const Quaternion & q, const Vec3 & v) {
	float tmpX = (((q.w * v.x) + (q.y * v.z)) - (q.z * v.y));
	float tmpY = (((q.w * v.y) + (q.z * v.x)) - (q.x * v.z));
	float tmpZ = (((q.w * v.z) + (q.x * v.y)) - (q.y * v.x));
	float tmpW = (((q.x * v.x) + (q.y * v.y)) + (q.z * v.z));
	return Vec3(((((tmpW * q.x) + (tmpX * q.w)) - (tmpY * q.z)) + (tmpZ * q.y)), ((((tmpW * q.y) + (tmpY * q.w)) - (tmpZ * q.x)) + (tmpX * q.z)), ((((tmpW * q.z) + (tmpZ * q.w)) - (tmpX * q.y)) + (tmpY * q.x)));
}

const Quaternion Quaternion::rotation(const Vec3 & v0, const Vec3 & v1) {
	float cha = sqrt((2.0f * (1.0f + v0.dot(v1))));
	float rcha = (1.0f / cha);
	return Quaternion((v0.cross(v1) * rcha), (cha * 0.5f));
}

const Quaternion Quaternion::rotation(float radians, const Vec3 & v) {
	float angle = radians * 0.5f;
	return Quaternion((v * sin(angle)), cos(angle));
}

const Quaternion Quaternion::rotX(float radians) {
	float angle = radians * 0.5f;
	return Quaternion(sin(angle), 0.0f, 0.0f, cos(angle));
}

const Quaternion Quaternion::rotY(float radians) {
	float angle = radians * 0.5f;
	return Quaternion(0.0f, sin(angle), 0.0f, cos(angle));
}

const Quaternion Quaternion::rotZ(float radians) {
	float angle = radians * 0.5f;
	return Quaternion(0.0f, 0.0f, sin(angle), cos(angle));
}
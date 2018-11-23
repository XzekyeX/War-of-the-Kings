#pragma once
#include "Math.h"
/**
*
* @author Mikko Tekoniemi
*
*/
struct Quaternion {
	float x, y, z, w;
	Quaternion() = default;
	Quaternion(const Quaternion& q);
	Quaternion(const float& x, const float& y, const float& z, const float& w);
	Quaternion(const Vec3& xyz, float w);
	Quaternion(const Vec4& v);
	Quaternion(float scalar);
	Quaternion& add(const Quaternion& other);
	Quaternion& subtract(const Quaternion& other);
	Quaternion& multiply(const Quaternion& other);
	Quaternion& divide(const Quaternion& other);
	Quaternion& add(float scalar);
	Quaternion& subtract(float scalar);
	Quaternion& multiply(float scalar);
	Quaternion& divide(float scalar);
	friend Quaternion operator+(Quaternion left, const Quaternion& right);
	friend Quaternion operator-(Quaternion left, const Quaternion& right);
	friend Quaternion operator*(Quaternion left, const Quaternion& right);
	friend Quaternion operator/(Quaternion left, const Quaternion& right);
	bool operator==(const Quaternion& other);
	bool operator!=(const Quaternion& other);
	Quaternion& operator+=(const Quaternion& other);
	Quaternion& operator-=(const Quaternion& other);
	Quaternion& operator*=(const Quaternion& other);
	Quaternion& operator/=(const Quaternion& other);
	float dot(const Quaternion& other) const;
	float length(const Quaternion& other) const;
	Quaternion conjugate();
	Vec3 getAxis() const;
	Vec3 getXYZ() const;
	Vec3 toEulerAngles();
	static Quaternion identity();
	static Quaternion fromEulerAngles(const Vec3& angles);
	static Vec3 rotate(const Quaternion& q, const Vec3& v);
	static const Quaternion rotation(const Vec3& v0, const Vec3& v1);
	static const Quaternion rotation(float radians, const Vec3& v);
	static const Quaternion rotX(float radians);
	static const Quaternion rotY(float radians);
	static const Quaternion rotZ(float radians);

};
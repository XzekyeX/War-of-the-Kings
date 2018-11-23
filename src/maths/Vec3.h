#pragma once

#include <iostream>
#include <iomanip>
/**
*
* @author Mikko Tekoniemi
*
*/
struct Vec3 {
	float x, y, z;
	Vec3();
	Vec3(const float& x, const float& y, const float& z);

	Vec3& add(const Vec3& other);
	Vec3& subtract(const Vec3& other);
	Vec3& multiply(const Vec3& other);
	Vec3& divide(const Vec3& other);

	Vec3& add(float scalar);
	Vec3& subtract(float scalar);
	Vec3& multiply(float scalar);
	Vec3& divide(float scalar);

	friend Vec3 operator+(Vec3 left, const Vec3& right);
	friend Vec3 operator-(Vec3 left, const Vec3& right);
	friend Vec3 operator*(Vec3 left, const Vec3& right);
	friend Vec3 operator/(Vec3 left, const Vec3& right);

	friend Vec3 operator+(Vec3 left, float scalar);
	friend Vec3 operator-(Vec3 left, float scalar);
	friend Vec3 operator*(Vec3 left, float scalar);
	friend Vec3 operator/(Vec3 left, float scalar);

	bool operator==(const Vec3& other);
	bool operator!=(const Vec3& other);

	Vec3& operator+=(const Vec3& other);
	Vec3& operator-=(const Vec3& other);
	Vec3& operator*=(const Vec3& other);
	Vec3& operator/=(const Vec3& other);

	Vec3& operator+=(float scalar);
	Vec3& operator-=(float scalar);
	Vec3& operator*=(float scalar);
	Vec3& operator/=(float scalar);

	Vec3 cross(const Vec3& other) const;
	float distance(const Vec3& other) const;
	float dot(const Vec3& other) const;
	float magnitude() const;
	Vec3 normalize() const;
	friend std::ostream& operator<<(std::ostream& stream, const Vec3& vector);
};
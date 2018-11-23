#pragma once
#define _USE_MATH_DEFINES
#include "Math.h"
/**
*
* @author Mikko Tekoniemi
*
*/
struct Mat4 {
	union {
		float elements[4 * 4];
		Vec4 rows[4];
	};
	Mat4();
	Mat4(float diagonal);
	Mat4& multiply(const Mat4& other);
	Vec3& multiply(const Vec3& other) const;
	Vec4& multiply(const Vec4& other) const;
	Mat4& operator*=(const Mat4& other);
	Mat4& invert();
	
	Vec4 getColumn(int index) const;
	void setColumn(unsigned int index, const Vec4& column);

	friend Mat4 operator*(Mat4 left, const Mat4& right);
	friend Vec3 operator*(const Mat4 left, const Vec3& right);
	friend Vec4 operator*(const Mat4 left, const Vec4& right);
	static Mat4 identity();

	static Mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
	static Mat4 perspective(float fov, float aspectRatio, float near, float far);
	static Mat4 lookAt(const Vec3& cam, const Vec3& obj, const Vec3& up);

	static Mat4 translate(const Vec3& translation);
	static Mat4 rotate(float angle, const Vec3& axis);
	//static Mat4 rotate(const Quaternion & q);
	static Mat4 scale(const Vec3& scale);
	static Mat4 invert(const Mat4& mat);

	friend std::ostream& operator<<(std::ostream& stream, const Mat4& m);

};
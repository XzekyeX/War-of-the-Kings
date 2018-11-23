#include "Mat4.h"
/**
*
* @author Mikko Tekoniemi
*
*/
float toRadians(float degrees) {
	return (float)(degrees * (M_PI / 180.0f));
}
Mat4::Mat4() {
	memset(elements, 0, 4 * 4 * sizeof(float));
}

Mat4::Mat4(float diagonal) {
	memset(elements, 0, 4 * 4 * sizeof(float));
	elements[0 + 0 * 4] = diagonal;
	elements[1 + 1 * 4] = diagonal;
	elements[2 + 2 * 4] = diagonal;
	elements[3 + 3 * 4] = diagonal;
}

Mat4& Mat4::multiply(const Mat4& other) {
	float result[16];
	for(int y = 0; y < 4; y++) {
		for(int x = 0; x < 4; x++) {
			float sum = 0.0f;
			for(int e = 0; e < 4; e++) {
				sum += elements[x + e * 4] * other.elements[e + y * 4];
			}
			result[x + y * 4] = sum;
		}
	}
	memcpy(elements, result, 4 * 4 * sizeof(float));
	return *this;
}

Vec4& Mat4::multiply(const Vec4& other) const {
	return Vec4(rows[0].x * other.x + rows[1].x * other.y + rows[2].x * other.z + rows[3].x * other.w, rows[0].y * other.x + rows[1].y * other.y + rows[2].y * other.z + rows[3].y * other.w, rows[0].z * other.x + rows[1].z * other.y + rows[2].z * other.z + rows[3].z * other.w, rows[0].w * other.x + rows[1].w * other.y + rows[2].w * other.z + rows[3].w * other.w);
}

Vec3& Mat4::multiply(const Vec3& other) const {
	return Vec3(rows[0].x * other.x + rows[1].x * other.y + rows[2].x * other.z + rows[3].x, rows[0].y * other.x + rows[1].y * other.y + rows[2].y * other.z + rows[3].y, rows[0].z * other.x + rows[1].z * other.y + rows[2].z * other.z + rows[3].z);
}

Vec4 operator*(const Mat4 left, const Vec4& right) {
	return left.multiply(right);
}

Vec3 operator*(const Mat4 left, const Vec3& right) {
	return left.multiply(right);
}

Mat4& Mat4::operator*=(const Mat4& other) {
	return multiply(other);
}

Mat4 operator*(Mat4 left, const Mat4& right) {
	return left.multiply(right);
}

Mat4 Mat4::identity() {
	return Mat4(1.0f);
}

Mat4 Mat4::orthographic(float left, float right, float bottom, float top, float near, float far) {
	Mat4 result(1.0f);
	result.elements[0 + 0 * 4] = 2.0f / (right - left);

	result.elements[1 + 1 * 4] = 2.0f / (top - bottom);

	result.elements[2 + 2 * 4] = 2.0f / (near - far);

	result.elements[3 + 0 * 4] = (left + right) / (left - right);
	result.elements[3 + 1 * 4] = (bottom + top) / (bottom - top);
	result.elements[3 + 2 * 4] = (far + near) / (far - near);
	return result;
}

Mat4 Mat4::perspective(float fov, float aspectRatio, float near, float far) {
	Mat4 result(1.0f);
	float q = 1.0f / (float)tan(toRadians(0.5f * fov));
	float a = q / aspectRatio;
	float b = (near + far) / (near - far);
	float c = (2.0f * near * far) / (near - far);
	result.elements[0 + 0 * 4] = a;
	result.elements[1 + 1 * 4] = q;
	result.elements[2 + 2 * 4] = b;
	result.elements[2 + 3 * 4] = -1.0f;
	result.elements[3 + 2 * 4] = c;
	return result;
}

Mat4 Mat4::lookAt(const Vec3 & cam, const Vec3 & obj, const Vec3 & up) {
	Mat4 result = identity();
	Vec3 f = (obj - cam).normalize();
	Vec3 s = f.cross(up.normalize());
	Vec3 u = s.cross(f);

	result.elements[0 + 0 * 4] = s.x;
	result.elements[0 + 1 * 4] = s.y;
	result.elements[0 + 2 * 4] = s.z;

	result.elements[1 + 0 * 4] = u.x;
	result.elements[1 + 1 * 4] = u.y;
	result.elements[1 + 2 * 4] = u.z;

	result.elements[2 + 0 * 4] = -f.x;
	result.elements[2 + 1 * 4] = -f.y;
	result.elements[2 + 2 * 4] = -f.z;

	return result * translate(Vec3(-cam.x, -cam.y, -cam.z));
}

Mat4 Mat4::translate(const Vec3& translation) {
	Mat4 result(1.0f);
	result.elements[3 + 0 * 4] = translation.x;
	result.elements[3 + 1 * 4] = translation.y;
	result.elements[3 + 2 * 4] = translation.z;
	return result;
}

Mat4 Mat4::rotate(float angle, const Vec3& axis) {
	Mat4 result(1.0f);
	float r = toRadians(angle);
	float c = cos(r);
	float s = sin(r);
	float omc = 1.0f - c;
	float x = axis.x;
	float y = axis.y;
	float z = axis.z;
	result.elements[0 + 0 * 4] = x * x * omc + c;
	result.elements[0 + 1 * 4] = y * x * omc + z * s;
	result.elements[0 + 2 * 4] = x * z * omc - y * s;

	result.elements[1 + 0 * 4] = x * y * omc - z * s;
	result.elements[1 + 1 * 4] = y * y * omc + c;
	result.elements[1 + 2 * 4] = y * z * omc + x * s;

	result.elements[2 + 0 * 4] = x * z * omc + y * s;
	result.elements[2 + 1 * 4] = y * z * omc - x * s;
	result.elements[2 + 2 * 4] = z * z * omc + c;
	return result;
}
//
//Mat4 Mat4::rotate(const Quaternion & q) {
//	Mat4 result = Mat4::identity();
//	result.columns[0] = Vec4(((1.0f - (q.y * (q.y + q.y))) - (q.z * (q.z + q.z))), ((q.x * (q.y + q.y)) - (q.w * (q.z + q.z))), ((q.x * (q.z + q.z)) + (q.w * (q.y + q.y))), 0.0f);
//	result.columns[1] = Vec4(((q.x * (q.y + q.y)) + (q.w * (q.z + q.z))), ((1.0f - (q.x * (q.x + q.x))) - (q.z * (q.z + q.z))), ((q.y * (q.z + q.z)) - (q.w * (q.x + q.x))), 0.0f);
//	result.columns[2] = Vec4(((q.x * (q.z + q.z)) - (q.w * (q.y + q.y))), ((q.y * (q.z + q.z)) + (q.w * (q.x + q.x))), ((1.0f - (q.x * (q.x + q.x))) - (q.y * (q.y + q.y))), 0.0f);
//	return result;
//}

Mat4 Mat4::scale(const Vec3& scale) {
	Mat4 result(1.0f);
	result.elements[0 + 0 * 4] = scale.x;
	result.elements[1 + 1 * 4] = scale.y;
	result.elements[2 + 2 * 4] = scale.z;
	return result;
}

Mat4 Mat4::invert(const Mat4 & mat) {
	Mat4 result = mat;
	return result.invert();
}

Mat4& Mat4::invert() {
	double temp[16];
	temp[0] = elements[5] * elements[10] * elements[15] - elements[5] * elements[11] * elements[14] - elements[9] * elements[6] * elements[15] + elements[9] * elements[7] * elements[14] + elements[13] * elements[6] * elements[11] - elements[13] * elements[7] * elements[10];

	temp[4] = -elements[4] * elements[10] * elements[15] + elements[4] * elements[11] * elements[14] + elements[8] * elements[6] * elements[15] - elements[8] * elements[7] * elements[14] - elements[12] * elements[6] * elements[11] + elements[12] * elements[7] * elements[10];

	temp[8] = elements[4] * elements[9] * elements[15] - elements[4] * elements[11] * elements[13] - elements[8] * elements[5] * elements[15] + elements[8] * elements[7] * elements[13] + elements[12] * elements[5] * elements[11] - elements[12] * elements[7] * elements[9];

	temp[12] = -elements[4] * elements[9] * elements[14] + elements[4] * elements[10] * elements[13] + elements[8] * elements[5] * elements[14] - elements[8] * elements[6] * elements[13] - elements[12] * elements[5] * elements[10] + elements[12] * elements[6] * elements[9];

	temp[1] = -elements[1] * elements[10] * elements[15] + elements[1] * elements[11] * elements[14] + elements[9] * elements[2] * elements[15] - elements[9] * elements[3] * elements[14] - elements[13] * elements[2] * elements[11] + elements[13] * elements[3] * elements[10];

	temp[5] = elements[0] * elements[10] * elements[15] - elements[0] * elements[11] * elements[14] - elements[8] * elements[2] * elements[15] + elements[8] * elements[3] * elements[14] + elements[12] * elements[2] * elements[11] - elements[12] * elements[3] * elements[10];

	temp[9] = -elements[0] * elements[9] * elements[15] + elements[0] * elements[11] * elements[13] + elements[8] * elements[1] * elements[15] - elements[8] * elements[3] * elements[13] - elements[12] * elements[1] * elements[11] + elements[12] * elements[3] * elements[9];

	temp[13] = elements[0] * elements[9] * elements[14] - elements[0] * elements[10] * elements[13] - elements[8] * elements[1] * elements[14] + elements[8] * elements[2] * elements[13] + elements[12] * elements[1] * elements[10] - elements[12] * elements[2] * elements[9];

	temp[2] = elements[1] * elements[6] * elements[15] - elements[1] * elements[7] * elements[14] - elements[5] * elements[2] * elements[15] + elements[5] * elements[3] * elements[14] + elements[13] * elements[2] * elements[7] - elements[13] * elements[3] * elements[6];

	temp[6] = -elements[0] * elements[6] * elements[15] + elements[0] * elements[7] * elements[14] + elements[4] * elements[2] * elements[15] - elements[4] * elements[3] * elements[14] - elements[12] * elements[2] * elements[7] + elements[12] * elements[3] * elements[6];

	temp[10] = elements[0] * elements[5] * elements[15] - elements[0] * elements[7] * elements[13] - elements[4] * elements[1] * elements[15] + elements[4] * elements[3] * elements[13] + elements[12] * elements[1] * elements[7] - elements[12] * elements[3] * elements[5];

	temp[14] = -elements[0] * elements[5] * elements[14] + elements[0] * elements[6] * elements[13] + elements[4] * elements[1] * elements[14] - elements[4] * elements[2] * elements[13] - elements[12] * elements[1] * elements[6] + elements[12] * elements[2] * elements[5];

	temp[3] = -elements[1] * elements[6] * elements[11] + elements[1] * elements[7] * elements[10] + elements[5] * elements[2] * elements[11] - elements[5] * elements[3] * elements[10] - elements[9] * elements[2] * elements[7] + elements[9] * elements[3] * elements[6];

	temp[7] = elements[0] * elements[6] * elements[11] - elements[0] * elements[7] * elements[10] - elements[4] * elements[2] * elements[11] + elements[4] * elements[3] * elements[10] + elements[8] * elements[2] * elements[7] - elements[8] * elements[3] * elements[6];

	temp[11] = -elements[0] * elements[5] * elements[11] + elements[0] * elements[7] * elements[9] + elements[4] * elements[1] * elements[11] - elements[4] * elements[3] * elements[9] - elements[8] * elements[1] * elements[7] + elements[8] * elements[3] * elements[5];

	temp[15] = elements[0] * elements[5] * elements[10] - elements[0] * elements[6] * elements[9] - elements[4] * elements[1] * elements[10] + elements[4] * elements[2] * elements[9] + elements[8] * elements[1] * elements[6] - elements[8] * elements[2] * elements[5];

	double det = elements[0] * temp[0] + elements[1] * temp[4] + elements[2] * temp[8] + elements[3] * temp[12];

	//if (det == 0) return false;

	det = 1.0 / det;

	for(int i = 0; i < 16; i++)
		elements[i] = temp[i] * det;
	return *this;
}

Vec4 Mat4::getColumn(int index) const {
	return Vec4(elements[index + 0 * 4], elements[index + 1 * 4], elements[index + 2 * 4], elements[index + 3 * 4]);
}

void Mat4::setColumn(unsigned int index, const Vec4 & column) {
	elements[index + 0 * 4] = column.x;
	elements[index + 1 * 4] = column.y;
	elements[index + 2 * 4] = column.z;
	elements[index + 3 * 4] = column.w;
}

std::ostream& operator<<(std::ostream& stream, const Mat4& m) {
	stream << "Mat4(" << m.rows[0].x << ", " << m.rows[1].x << ", " << m.rows[2].x << ", " << m.rows[3].x << "), ";
	stream << "(" << m.rows[0].y << ", " << m.rows[1].y << ", " << m.rows[2].y << ", " << m.rows[3].y << "), ";
	stream << "(" << m.rows[0].z << ", " << m.rows[1].z << ", " << m.rows[2].z << ", " << m.rows[3].z << "), ";
	stream << "(" << m.rows[0].w << ", " << m.rows[1].w << ", " << m.rows[2].w << ", " << m.rows[3].w << ")";
	return stream;
}
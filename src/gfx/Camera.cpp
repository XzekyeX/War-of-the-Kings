#include "Camera.h"
/**
*
* @author Mikko Tekoniemi
*
*/

Camera::Camera(const Mat4 & pr_matrix) {
	this->pr_matrix = pr_matrix;
	this->vw_matrix = Mat4::identity();
	this->pos = Vec3();
	this->rot = Vec3();
}

const Vec3 & Camera::getPos() const {
	return pos;
}

void Camera::setPos(const Vec3 & pos) {
	this->pos = pos;
}

const Vec3 & Camera::getRot() const {
	return rot;
}

void Camera::setRot(const Vec3 & rot) {
	this->rot = rot;
}

const Mat4 & Camera::getProjectionMatrix() const {
	return pr_matrix;
}

const Mat4 & Camera::getViewMatrix() const {
	return vw_matrix;
}

void Camera::translate(const Vec3 & v) {
	this->pos += v;
}

void Camera::rotate(const Vec3 & v) {
	this->rot += v;
}

void Camera::translate(float x, float y, float z) {
	this->pos += Vec3(x, y, z);
}

void Camera::rotate(float x, float y, float z) {
	this->rot += Vec3(x, y, z);
}

const Vec3 & Camera::getFocalPoint() const {
	return fpoint;
}

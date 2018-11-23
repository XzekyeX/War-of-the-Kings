#pragma once
#include "Camera.h"
/**
*
* @author Mikko Tekoniemi
*
*/
class FPSCamera : public Camera {
private:
	float sensitivity;
	float speed, sprintSpeed;
	float pitch, yaw;
	bool isMouseGrabbed;
public:
	FPSCamera(const Mat4& pr_matrix);
	void focus() override;
	void update() override;

private:
	Quaternion getOrientation() const;
	Vec3 getForwardDir(const Quaternion& o) const;
	Vec3 getUpDir(const Quaternion& o) const;
	Vec3 getRightDir(const Quaternion& o) const;
};
#include "FPSCamera.h"

FPSCamera::FPSCamera(const Mat4 & pr_matrix) : Camera(pr_matrix), sensitivity(0.002f), speed(0.4f), sprintSpeed(speed * 4.0f), isMouseGrabbed(false) {
	this->pos = Vec3(0.0f, 25.0f, -25.0f);
	this->rot = Vec3(90.0f, 0.0f, 0.0f);
	this->yaw = 2.4f;
	this->pitch = 0.7f;
}

void FPSCamera::focus() {}

void FPSCamera::update() {
	
}


#pragma once
#include "../maths/Math.h"

/**
*
* @author Mikko Tekoniemi
*
*/

class Camera {
protected:
	Mat4 pr_matrix, vw_matrix;
	Vec3 pos, rot, fpoint;
public:
	Camera(const Mat4& pr_matrix);

	virtual void update() = 0;
	virtual void focus() = 0;

	const Vec3& getPos() const;
	void setPos(const Vec3& pos);

	const Vec3& getRot() const;
	void setRot(const Vec3& rot);

	const Mat4& getProjectionMatrix() const;

	const Mat4& getViewMatrix() const;

	void translate(const Vec3& v);
	void rotate(const Vec3& v);

	void translate(float x, float y, float z);
	void rotate(float x, float y, float z);

	const Vec3& getFocalPoint() const;

};
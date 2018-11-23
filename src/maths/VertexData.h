#pragma once
#include "Math.h"
/**
*
* @author Mikko Tekoniemi
*
*/
struct VertexData {
	Vec3 position;
	Vec2 texture;
	Vec3 normal;
	VertexData(Vec3 position, Vec2 textre, Vec3 normal) : position(position), texture(texture), normal(normal) {

	}
};

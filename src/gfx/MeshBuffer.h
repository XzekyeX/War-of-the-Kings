#pragma once
#include "../utils/StringUtils.h"
#include "../utils/File.h"
#include "../utils/FaceElement.h"
#include "../maths/Math.h"
/**
*
* @author Mikko Tekoniemi
*
*/
class MeshBuffer {
	friend class Mesh;
protected:
	std::vector<VertexData> vertex;
	std::vector<unsigned int> indices;
public:
	MeshBuffer(std::vector<VertexData> vertex, std::vector<unsigned int> indices) : vertex(vertex), indices(indices) {

	}

	static MeshBuffer loadModel(const char* path);
private:
	static MeshBuffer reorder(std::vector<Vec3> vertices, std::vector<Vec2> textures, std::vector<Vec3> normals, std::vector<FaceElement> faces);
};
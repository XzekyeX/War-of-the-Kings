#include "MeshBuffer.h"
#define equals(str,delim) strstr(str,delim)

/**
*
* @author Mikko Tekoniemi
*
*/

MeshBuffer MeshBuffer::loadModel(const char* path) {
	std::vector<std::string> lines = split(File::readFile(path), '\n');
	std::vector<Vec3> vertices;
	std::vector<Vec2> textures;
	std::vector<Vec3> normals;
	std::vector<FaceElement> faces;
	for(std::string line : lines) {
		std::vector<std::string> tokens = split(line, ' ');
		if(tokens.size() > 0) {
			const char* first = tokens[0].c_str();
			if(!equals(first, "#")) {
				if(equals(first, "v") && tokens.size() > 3) {
					vertices.push_back(Vec3(toFloat(tokens[1], 0), toFloat(tokens[2], 0), toFloat(tokens[3], 0)));
				}
				if(equals(first, "vt") && tokens.size() > 2) {
					textures.push_back(Vec2(toFloat(tokens[1], 0), toFloat(tokens[2], 0)));
				}
				if(equals(first, "vn") && tokens.size() > 3) {
					normals.push_back(Vec3(toFloat(tokens[1], 0), toFloat(tokens[2], 0), toFloat(tokens[3], 0)));
				}
				if(equals(first, "f") && tokens.size() > 3) {
					FaceElement face({tokens[1], tokens[2], tokens[3]});
					faces.push_back(face);
					if(tokens.size() > 4) {
						FaceElement face1({tokens[1], tokens[3], tokens[4]});
						faces.push_back(face1);
					}
				}
			} else {
				continue;
			}
		} else {
			continue;
		}
	}
	return reorder(vertices, textures, normals, faces);
}

MeshBuffer MeshBuffer::reorder(std::vector<Vec3> vertices, std::vector<Vec2> textures, std::vector<Vec3> normals, std::vector<FaceElement> faces) {
	std::vector<VertexData> vData;
	std::vector<unsigned int> indices;

	for(FaceElement f : faces) {
		for(IndexElement v : f.indices) {
			int index = v.vertex - 1;
			indices.push_back(index);
			Vec3 p = vertices[index];
			Vec2 t;
			Vec3 n;
			if(v.texture >= 0) t = textures[v.texture - 1];
			if(v.normal >= 0) n = normals[v.normal - 1];
			VertexData data(p, t, n);
			vData.push_back(data);
		}
	}

	return{vData,indices};
}

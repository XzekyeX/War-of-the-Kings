#pragma once
#include "../OpenGL.h"
#include "MeshBuffer.h"
/**
*
* @author Mikko Tekoniemi
*
*/
class Mesh {
protected:
	unsigned int vao;
	unsigned int vbo;
	unsigned int ibo;
	const unsigned int VERTEX_ATTRIB = 0;
	const unsigned int TCOORD_ATTRIB = 1;
	const unsigned int NORMAL_ATTRIB = 2;
	MeshBuffer buffer;
public:
	Mesh(MeshBuffer buffer) : buffer(buffer) {
		genBuffers();
	}
private:
	void genBuffers();
public:
	void bind();
	void unbind();
	void draw();
	void render();
};
#include "Mesh.h"
/**
*
* @author Mikko Tekoniemi
*
*/
void Mesh::genBuffers() {
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	unsigned int vertex_size = sizeof(VertexData);
	print("Vertex Size: ");
	println(vertex_size);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, buffer.vertex.size() * vertex_size, buffer.vertex.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(VERTEX_ATTRIB, 3, GL_FLOAT, false, vertex_size, (const void*)offsetof(VertexData, VertexData::position));
	glVertexAttribPointer(TCOORD_ATTRIB, 2, GL_FLOAT, false, vertex_size, (const void*)offsetof(VertexData, VertexData::texture));
	glVertexAttribPointer(NORMAL_ATTRIB, 3, GL_FLOAT, false, vertex_size, (const void*)offsetof(VertexData, VertexData::normal));
	
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, buffer.indices.size() * sizeof(unsigned int), buffer.indices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Mesh::bind() {
	glBindVertexArray(vao);
	glEnableVertexAttribArray(VERTEX_ATTRIB);
	glEnableVertexAttribArray(TCOORD_ATTRIB);
	glEnableVertexAttribArray(NORMAL_ATTRIB);
}

void Mesh::unbind() {
	glDisableVertexAttribArray(VERTEX_ATTRIB);
	glDisableVertexAttribArray(TCOORD_ATTRIB);
	glDisableVertexAttribArray(NORMAL_ATTRIB);
	glBindVertexArray(0);
}

void Mesh::draw() {
	glDrawElements(GL_TRIANGLES, buffer.indices.size(), GL_UNSIGNED_INT, nullptr);
}

void Mesh::render() {
	bind();
	draw();
	unbind();
}

#include "War of the Kings.h"
/**
*
* @author Mikko Tekoniemi
*
*/

WOTK::WOTK() : Window("War of the Kings", 640, 480) {

}

//MeshBuffer * buffer;
Mesh * mesh;
Mat4 * ml_matrix;
Shader * shader;
void WOTK::init() {
	Mat4 pr_matrix = Mat4::perspective(60, getWidth() / getHeight(), 0.01f, -1.0f);
	ml_matrix = &Mat4::identity();
	//Mat4 ml_matrix = Mat4::identity();
	//Shader shader("res/shaders/basic.shader");
	shader = new Shader("res/shaders/basic.shader");
	shader->bind();
	//shader.setUniform("pr_matrix", pr_matrix);
	Mat4& mat = *ml_matrix;
	shader->setUniform("ml_matrix", mat);
	MeshBuffer buffer = MeshBuffer::loadModel("res/models/lowpolytree.obj");

	mesh = new Mesh(buffer);
}


void WOTK::update() {
	Mat4& mat = *ml_matrix;
	if(Input::isKeyDown(KEY_W)) {
		mat.translate(Vec3(0, 0, 0.01f));
		shader->setUniform("ml_matrix", mat);
		println(mat);
	}
	if(Input::isKeyDown(KEY_S)) {
		mat.translate(Vec3(0, 0, -0.01f));
		shader->setUniform("ml_matrix", mat);
		println(mat);
	}
	if(Input::isKeyDown(KEY_D)) {
		mat.translate(Vec3(0.01f, 0, 0));
		shader->setUniform("ml_matrix", mat);
		println(mat);
	}
	if(Input::isKeyDown(KEY_A)) {
		mat.translate(Vec3(-0.01f, 0, 0));
		shader->setUniform("ml_matrix", mat);
		println(mat);
	}
}

void WOTK::render() {
	mesh->render();
}


int main(void) {
	WOTK* w = new WOTK();

	w->start();
	return 0;
}

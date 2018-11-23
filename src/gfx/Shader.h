#pragma once
#include "../OpenGL.h"
#include "../maths/Math.h"
#include "../utils/File.h"
/**
*
* @author Mikko Tekoniemi
*
*/
class Shader {
public:
	Shader(const std::string& vert, const std::string& frag) {
		const std::string& v = File::loadShader(vert.c_str());
		const std::string& f = File::loadShader(frag.c_str());
		program = create(v, f);
	}

	Shader(const std::string& shader) {
		FileShader s = File::loadShaders(shader.c_str());
		program = create(s.vertex, s.fragment);
	}
private:
	unsigned int program;
	std::map<std::string, int> uniforms;
	unsigned int create(const std::string& vert, const std::string& frag);
	unsigned int compile(unsigned int type, const std::string& src);
public:
	void bind();
	void unbind();
	int getUniform(const std::string& name);
	void setUniform(const std::string& name, int value);
	void setUniform(const std::string& name, float value);
	void setUniform(const std::string& name, const Vec2& value);
	void setUniform(const std::string& name, const Vec3& value);
	void setUniform(const std::string& name, const Vec4& value);
	void setUniform(const std::string& name, const Mat4& value);

};
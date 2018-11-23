#include "Shader.h"
/**
*
* @author Mikko Tekoniemi
*
*/
unsigned int Shader::compile(unsigned int type, const std::string& src) {
	unsigned int id = glCreateShader(type);
	const char* str = src.c_str();
	glShaderSource(id, 1, &str, nullptr);
	glCompileShader(id);
	int status = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &status);
	if(status == GL_FALSE) {
		std::cout << "Failed to compile " << (type != GL_VERTEX_SHADER ? "fragment" : "vertex") << " shader!" << std::endl;
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}
	return id;
}

unsigned int Shader::create(const std::string& vert, const std::string& frag) {
	unsigned int program = glCreateProgram();
	unsigned int vertID = compile(GL_VERTEX_SHADER, vert);
	unsigned int fragID = compile(GL_FRAGMENT_SHADER, frag);
	if(vertID <= 0 || fragID <= 0) return 0;
	glAttachShader(program, vertID);
	glAttachShader(program, fragID);
	glLinkProgram(program);
	glValidateProgram(program);
	glDeleteShader(vertID);
	glDeleteShader(fragID);
	return program;
}

void Shader::bind() {
	glUseProgram(program);
}

void Shader::unbind() {
	glUseProgram(0);
}

int Shader::getUniform(const std::string& name) {
	if(uniforms.find(name) != uniforms.end()) return uniforms[name];
	int result = glGetUniformLocation(program, name.c_str());
	if(result < 0) {
		println("Could not find uniform variable " << name << "! result: " + result);
	} else {
		uniforms[name] = result;
	}
	return result;
}

void Shader::setUniform(const std::string& name, int value) {
	glUniform1i(getUniform(name), value);
}

void Shader::setUniform(const std::string& name, float value) {
	glUniform1f(getUniform(name), value);
}

void Shader::setUniform(const std::string& name, const Vec2& value) {
	glUniform2f(getUniform(name), value.x, value.y);
}

void Shader::setUniform(const std::string& name, const Vec3& value) {
	glUniform3f(getUniform(name), value.x, value.y, value.z);
}

void Shader::setUniform(const std::string& name, const Vec4& value) {
	glUniform4f(getUniform(name), value.x, value.y, value.z, value.w);
}

void Shader::setUniform(const std::string & name, const Mat4 & value) {
	glUniformMatrix4fv(getUniform(name), 1, GL_FALSE, value.elements);
}

#pragma once
#include "../utils/StringUtils.h"
#include "../gfx/MeshBuffer.h"
#include "FileShader.h"
/**
*
* @author Mikko Tekoniemi
*
*/
class File {
public:
	static std::string loadShader(const char* path);
	static FileShader loadShaders(const char* path);
	static std::string readFile(const char* path);
};
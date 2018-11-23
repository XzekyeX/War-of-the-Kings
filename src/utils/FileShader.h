#pragma once
/**
*
* @author Mikko Tekoniemi
*
*/
struct FileShader {
	std::string vertex;
	std::string fragment;
	FileShader(std::string vertex, std::string fragment) : vertex(vertex), fragment(fragment) {

	}

};
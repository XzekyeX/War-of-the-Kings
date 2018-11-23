#pragma once
#include "IndexElement.h"
/**
*
* @author Mikko Tekoniemi
*
*/
struct FaceElement {
	std::vector<IndexElement> indices;
	
	FaceElement(std::vector<std::string> tokens) {
		for(std::string token : tokens) {
			IndexElement index(token);
			indices.push_back(index);
		}
	}
};
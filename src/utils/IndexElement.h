#pragma once
#include "StringUtils.h"
/**
*
* @author Mikko Tekoniemi
*
*/
struct IndexElement {
	int vertex = -1;
	int texture = -1;
	int normal = -1;
	IndexElement(std::string str) {
		std::vector<std::string> tokens = split(str, '/');
		if(tokens.size() > 0) {
			vertex = toInt(tokens[0], -1);
			if(tokens.size() > 1) {
				texture = toInt(tokens[1], -1);
				if(tokens.size() > 2) {
					normal = toInt(tokens[2], -1);
				}
			}
		}
	}
};
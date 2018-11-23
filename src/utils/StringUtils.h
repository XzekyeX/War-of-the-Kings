#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#define println(str) std::cout << str << std::endl;
#define print(str) std::cout << str;
#define toStr(data,length) print("["); for(int i = 0; i < length; i++){print(data[i]); if(i < length - 1) {print(", ");} else {println("]");}};
#define DEBUG false
/**
*
* @author Mikko Tekoniemi
*
*/
static std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> result;
	std::stringstream ss(s);
	std::string item;
	while(std::getline(ss, item, delim)) {
		result.push_back(item);
	}
	return result;
}

static int toInt(std::string str, int defValue) {
	try {
		int result = std::stoi(str);
		return result;
	} catch(std::invalid_argument& e) {
#if DEBUG
		std::cout << "Conversion couldn't be performed! str: " << str << std::endl;
#endif
	}
	return defValue;
}

static float toFloat(std::string str, float defValue) {
	try {
		float result = std::stof(str);
		return result;
	} catch(std::invalid_argument& e) {
#if DEBUG
		std::cout << "Conversion couldn't be performed! str: " << str << std::endl;
#endif
	}
	return defValue;
}
#include "File.h"
/**
*
* @author Mikko Tekoniemi
*
*/
FileShader File::loadShaders(const char* path) {
	std::ifstream file(path);
	std::string line;
	std::stringstream result[2];
	int type = -1;
	while(getline(file, line)) {
		if(line.find("#shader") != std::string::npos) {
			if(line.find("vertex") != std::string::npos) {
				type = 0;
			} else if(line.find("fragment") != std::string::npos) {
				type = 1;
			} else {
				type = -1;
			}
		} else {
			if(type >= 0) result[type] << line << "\n";
			else std::cout << "Failed to read shader file!" << std::endl;
		}
	}
	return{result[0].str(),result[1].str()};
}

std::string File::readFile(const char * path) {
	FILE* file;
	fopen_s(&file, path, "rt");
	fseek(file, 0, SEEK_END);
	unsigned long length = ftell(file);
	char* data = new char[length + 1];
	memset(data, 0, length + 1);
	fseek(file, 0, SEEK_SET);
	fread(data, 1, length, file);
	fclose(file);
	std::string result(data);
	delete[] data;
	return result;
}


std::string File::loadShader(const char* path) {
	std::ifstream file(path);
	std::string line;
	std::stringstream result;
	while(getline(file, line)) {
		result << line << '\n';
	}
	return result.str();
}

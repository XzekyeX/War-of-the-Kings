#pragma once
#include "utils/StringUtils.h"
#include <thread>
#include "OpenGL.h"
#include "gfx/Shader.h"
#include "gfx/Mesh.h"
#include "Input.h"
/**
*
* @author Mikko Tekoniemi
*
*/
class Window {
public:
	Window(const char* title, int width, int height) : title(title), width(width), height(height) {}
private:
	int width, height;
	const char* title;
	//std::thread* thread;
	GLFWwindow* window;
	//Input* input;
	bool running = false;
	bool createWindow();
	bool initialize();
	void run();
	void tick();

public:
	void start();
	void stop();
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	int getWidth() const;
	int getHeight() const;
};
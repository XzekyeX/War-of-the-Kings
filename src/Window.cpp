// War of the Kings.cpp : Defines the entry point for the console application.
//


#include "Window.h"

/**
*
* @author Mikko Tekoniemi
*
*/
bool Window::createWindow() {
	if(!glfwInit()) {
		std::cout << "Unable to initialize GLFW!" << std::endl;
		return false;
	}
	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
	window = glfwCreateWindow(width, height, title, NULL, NULL);
	if(!window) {
		std::cout << "Failed to create the GLFW window!" << std::endl;
		glfwTerminate();
		return false;
	}
	const GLFWvidmode* vm = glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowPos(window, (vm->width - width) / 2, (vm->height - height) / 2);
	glfwMakeContextCurrent(window);

	if(glewInit() != GLEW_OK) {
		std::cout << "Unable to initialize GLEW!" << std::endl;
		return false;
	}

	std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

	glfwSetKeyCallback(window, Input::key_callback);
	glfwSetMouseButtonCallback(window, Input::button_callback);
	glfwSetCursorPosCallback(window, Input::cursor_callback);

	glfwSwapInterval(0);
	glfwShowWindow(window);
}

bool Window::initialize() {
	if(createWindow()) {
		init();
		return true;
	}
	return false;
}

void Window::run() {
	double lastTime = glfwGetTime();
	double timer = lastTime;
	double delta = 0;
	double ns = 1.0 / 60.0;
	int fps = 0;
	int ups = 0;
	if(!initialize()) return;
	while(running) {
		double now = glfwGetTime();
		delta += (now - lastTime) / ns;
		lastTime = now;
		//setDelta(delta);
		while(delta >= 1.0) {
			tick();
			ups++;
			delta--;
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		render();
		fps++;
		glfwSwapBuffers(window);
		glfwPollEvents();
		if(glfwGetTime() - timer > 1.0) {
			timer++;
			println("fps[" << fps << "], ups[" << ups << "]");
			fps = 0;
			ups = 0;
		}
		if(glfwWindowShouldClose(window)) {
			glfwTerminate();
			stop();
		}
	}
}

void Window::tick() {
	Input::update();
	update();
	unsigned int error = glGetError();
	if(error != GL_NO_ERROR) {
		println("OpenGL Error: " << error);
	}
}


void Window::start() {
	if(running) return;

	running = true;
	run();
}


void Window::stop() {
	if(!running) return;
	//thread->join();
	//std::terminate();
	std::cout << "stop!" << std::endl;
}

int Window::getHeight() const {
	return height;
}

int Window::getWidth() const {
	return width;
}

#include "Input.h"

bool Input::keys[MAX_KEYS];
bool Input::keyTyped[MAX_KEYS];
bool Input::keyState[MAX_KEYS];
bool Input::buttons[MAX_BUTTONS];
bool Input::buttonState[MAX_BUTTONS];
bool Input::buttonClicked[MAX_BUTTONS];
double Input::mouseX, Input::mouseY;

Input::Input() {

}

void Input::update() {
	for(int i = 0; i < MAX_KEYS; i++)
		keyTyped[i] = keys[i] && !keyState[i];
	for(int i = 0; i < MAX_KEYS; i++)
		keyState[i] = keys[i];
	for(int i = 0; i < MAX_BUTTONS; i++)
		buttonClicked[i] = buttons[i] && !buttonState[i];
	for(int i = 0; i < MAX_BUTTONS; i++)
		buttonState[i] = buttons[i];
}

bool Input::isKeyDown(unsigned int key) {
	if(key >= 0 && key <= MAX_KEYS - 1) return keys[key];
	return false;
}

bool Input::isKeyTyped(unsigned int key) {
	if(key >= 0 && key <= MAX_KEYS - 1) return keyTyped[key];
	return false;
}

bool Input::isButtonDown(unsigned int key) {
	if(key >= 0 && key <= MAX_BUTTONS - 1) return buttons[key];
	return false;
}

bool Input::isButtonClicked(unsigned int key)  {
	if(key >= 0 && key <= MAX_BUTTONS - 1) return buttonClicked[key];
	return false;
}

void Input::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
	keys[key] = action != 0;
}

void Input::button_callback(GLFWwindow *window, int button, int action, int mods) {
	buttons[button] = action != 1;
}

void Input::cursor_callback(GLFWwindow *window, double xpos, double ypos) {
	mouseX = xpos;
	mouseY = ypos;
}


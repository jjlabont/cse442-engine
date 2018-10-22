#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Input.h"


InputSource::InputSource(GLFWwindow *window) {
	for (int i = 0; i < NUM_KEYS; i++)
	{
		key[i] = false;
		keyUp[i] = false;
		keyDown[i] = false;

	}
	for (int i = 0; i < NUM_KEYS; i++)
	{
		mousePressed[i] = false;
		mouseButtonUp[i] = false;
		mouseButtonDown[i] = false;

	}
	this->window = window;
}

void InputSource::update() {
	for (int i = 0; i < NUM_KEYS; i++) {
		GLFWwindow* windowTemp = window;
		if (!key[i] && glfwGetKey(window, i))
		{
			keyDown[i] = true;
		}
		else
			keyDown[i] = false;

		if (key[i] && !glfwGetKey(window, i))
			keyUp[i] = true;
		else
			keyUp[i] = false;

		key[i] = glfwGetKey(window, i);

		if (!mousePressed[i] && glfwGetMouseButton(window, i))
		{
			mousePressed[i] = true;
		}
		else
			mouseButtonDown[i] = false;

		if (mousePressed[i] && !glfwGetMouseButton(window, i))
			mouseButtonUp[i] = true;
		else
			mouseButtonUp[i] = false;

		if (glfwGetMouseButton(window, i))
			mousePressed[i] = false;

		window = windowTemp;
	}
}

bool InputSource::getKey(int i)
{
	return key[i];
}
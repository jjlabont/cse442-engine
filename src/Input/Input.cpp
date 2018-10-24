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
		mouse[i] = false;
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

		if (!mouse[i] && glfwGetMouseButton(window, i))
		{
			mouse[i] = true;
		}
		else
			mouseButtonDown[i] = false;

		if (mouse[i] && !glfwGetMouseButton(window, i))
			mouseButtonUp[i] = true;
		else
			mouseButtonUp[i] = false;

		mouse[i] = glfwGetMouseButton(window, i);

		window = windowTemp;
	}
}

bool InputSource::getKey(int i)
{
	return key[i];
}

bool InputSource::getKeyDown(int i)
{
	return keyDown[i];
}

bool InputSource::getKeyUp(int i)
{
	return keyUp[i];
}

bool InputSource::getMouse(int i)
{
	return mouse[i];
}

bool InputSource::getMouseDown(int i)
{
	return mouseButtonDown[i];
}

bool InputSource::getMouseUp(int i)
{
	return mouseButtonUp[i];
}
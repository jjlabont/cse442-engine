#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

#include <GL/glew.h>
#include <GLFW/glfw3.h>



class InputSource {
private:
	const static int NUM_KEYS = 512;
	const static int NUM_MOUSE_BUTTONS = 20;
	bool key[NUM_KEYS];
	bool keyUp[NUM_KEYS];
	bool keyDown[NUM_KEYS];

	float mouseX;
	float mouseY;
	bool mouse[NUM_MOUSE_BUTTONS];
	bool mouseButtonUp[NUM_MOUSE_BUTTONS];
	bool mouseButtonDown[NUM_MOUSE_BUTTONS];


	GLFWwindow* window;
	
public:
	InputSource(GLFWwindow *window = nullptr);
	bool getKey(int i);
	bool getKeyDown(int i);
	bool getKeyUp(int i);
	bool getMouse(int i);
	bool getMouseDown(int i);
	bool getMouseUp(int i);

	void update();
	
};
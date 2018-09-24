#pragma once
#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Graphics.h"

class GOAT_Engine{
private:
	GLFWwindow* window;
	unsigned int windowWidth;
	unsigned int windowHeight; 
	

	std::vector<Sprite*> sprites;

public:

	//make private later

	GraphicSource graphicSource;

	GOAT_Engine(int w, int h, const char* title);
	~GOAT_Engine();

	bool shouldClose();
	void addSprite(Sprite* sprite);
	void draw();
	void terminate();
};
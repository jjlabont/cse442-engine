#pragma once
#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "EngineTimer.h"
#include "Graphics.h"

class GOAT_Engine {
private:
	GLFWwindow* window;
	unsigned int windowWidth;
<<<<<<< HEAD
	unsigned int windowHeight;
	EngineTimer timer;
	std::vector<Sprite*> sprites;

public:
	GraphicSource graphicSource;
	GOAT_Engine(int w, int h, const char* title, unsigned int fps = 60);
=======
	unsigned int windowHeight; 
	
	Renderer renderer;
	Shader* shader;
	Shader* shader2;

	std::vector<Sprite*> sprites;

public:
	GOAT_Engine(int w, int h, const char* title);
>>>>>>> opengl-setup
	~GOAT_Engine();
	bool shouldClose();
	void addSprite(Sprite* sprite);
	void draw();
	void showFPS();
	void setFPS(unsigned int fps);
	void terminate();
};
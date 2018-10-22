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
	EngineTimer timer;

	Renderer renderer;
	Shader* shader;
	Shader* shader2;

	std::vector<Sprite*> sprites;

public:
	GOAT_Engine(int w, int h, const char* title, unsigned int fps = 60);
	~GOAT_Engine();
	void toggleDebug();
	void setFPS(unsigned int fps);

	void draw();
	void addSprite(Sprite* sprite);

	bool shouldClose();
	void terminate();
};
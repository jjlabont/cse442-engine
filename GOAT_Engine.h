#pragma once
//resource includes
#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

//goat engine headers
#include "Input.h"
#include "EngineTimer.h"
#include "Graphics.h"
#include "Texture.h"

class GOAT_Engine {
private:
	GLFWwindow* window;
	EngineTimer timer;

	Renderer renderer;
	Shader* shader;

	std::vector<Sprite*> sprites;
	Texture* texture;

	unsigned int windowWidth;
	unsigned int windowHeight;
	InputSource input;
public:


	GOAT_Engine(int w, int h, const char* title, unsigned int fps = 60);
	~GOAT_Engine();

	void toggleDebug();

	void setFPS(unsigned int fps);

	void draw();
	void addSprite(Sprite* sprite);

	void pollEvents();

	bool shouldClose();
	void terminate();

	InputSource& getInput();
};
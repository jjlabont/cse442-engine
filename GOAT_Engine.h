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
	double lastTime = 0; //last time since frame count initialized for frame counter
	double nextFrameTime = 0; //time the next fame should be rendered at
	double numFrames = 0; //number of frames
	double maxFPS; //cap on frame rate
	void limitFPS();
	std::vector<Sprite*> sprites;

public:
	GraphicSource graphicSource;

	GOAT_Engine(int w, int h, const char* title);
	~GOAT_Engine();
	bool shouldClose();
	void addSprite(Sprite* sprite);
	void draw();
	void terminate();
	void showFPS();
	void setMaxFPS(double FPS);
};
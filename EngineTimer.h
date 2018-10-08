#pragma once
#include <GLFW/glfw3.h>
# include <iostream>
class EngineTimer {
private:

	double lastTime = 0; //last time since frame count initialized for frame counter
	double nextFrameTime = 0; //time the next fame should be rendered at
	double numFrames = 0; //number of frames
	unsigned int FPS; //cap on frame rate
public:
	EngineTimer(unsigned int fps = 60);
	~EngineTimer();
	void limitFPS();
	void showFPS();
	void setFPS(unsigned int fps);
};
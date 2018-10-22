#pragma once
#include <GLFW/glfw3.h>
# include <iostream>
class EngineTimer {
private:

	double lastTime = 0; //last time since frame count initialized for frame counter
	double nextFrameTime = 0; //time the next fame should be rendered at
	double numFrames = 0; //number of frames
	unsigned int FPS; //cap on frame rate
	long inGameTime = 0;
	long realTimeElapsed = 0;
	bool FPSCounterEnabled = 0;

	void limitFPS();
	void showFPS();

public:
	EngineTimer(unsigned int fps = 60);
	~EngineTimer();

	void setFPS(unsigned int fps);
	void toggleFPSDisplay();

	void updateIGT();
	void updateRealTime();
	void update();
	void displayCurrentTimes();
};
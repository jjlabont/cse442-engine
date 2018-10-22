#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

struct Time {
	int days;
	int hours;
	int mins;
	double secs;

	Time() {
		days = 0;
		hours = 0;
		mins = 0;
		secs = 0;
	}
};

class EngineTimer {
private:

	double lastTime = 0; //last time since frame count initialized for frame counter
	double nextFrameTime = 0; //time the next fame should be rendered at
	double numFrames = 0; //number of frames
	unsigned int FPS; //cap on frame rate
	Time inGameTimeElapsed;
	Time realTimeElapsed;
	double inGameTimer = 0;
	double realTimeTimer = 0;
	bool debugEnabled = 0;
	unsigned int numSpritesDrawn;

	void limitFPS();
	void printDebugMsg();

public:
	EngineTimer(unsigned int fps = 60);
	~EngineTimer();

	void setFPS(unsigned int fps);
	void toggleDebug();

	void updateIGT();
	void updateRealTime();
	void update(unsigned int numSprites);
	void displayCurrentTimes();
};
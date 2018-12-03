#include "EngineTimer.h"

EngineTimer::EngineTimer(unsigned int fps) {
	if (fps <= 0) {
		//Change to error stack
		std::cout << "Invalid FPS entered, defaulting to 60FPS" << std::endl;
		FPS = 60;

	}
	else {
		FPS = fps;
	}

	inGameTimeElapsed = Time();
	realTimeElapsed = Time();
}

EngineTimer::~EngineTimer() {

}

//updates the timer
void EngineTimer::update(unsigned int numSprites) {
	numSpritesDrawn = numSprites;
	//updateIGT();
	//updateRealTime();
	limitFPS();
	updateDelta();
}

void EngineTimer::updateIGT() {
	inGameTimer += 1.0 / FPS;
}

void EngineTimer::updateRealTime() {
	realTimeTimer = glfwGetTime();
	int hours = 0;
	int mins = (realTimeTimer - (hours * 3600) / 60);
	int secs;
	//std::cout << realTimeElapsed << std::endl;
}

//toggles if FPS is being displayed
void EngineTimer::toggleDebug() {
	debugEnabled = !debugEnabled;
}


/*
Calculates number of frames per second (FPS) and milliseconds per frame (ms/frame)
and ouputs them to console
16.6 ms/frame is about 60fps
*/
void EngineTimer::updateDelta() {
		double currentTime = glfwGetTime();
		delta = currentTime - lastTime; //delta is change in time
		lastTime = currentTime;
}

//limits amount of fps
void EngineTimer::limitFPS() {
	//if current frame is rendered and it hasn't been the amount of time for the next frame program will wait
	while (glfwGetTime() < nextFrameTime + 1.0 / FPS) {
		//Do nothing
	}
	//set nextFrames time
	nextFrameTime += 1.0 / FPS;

}


//sets maximum amount of FPS
void EngineTimer::setFPS(unsigned int fps) {
	if (fps <= 0) {
		//Change to error stack
		std::cout << "Invalid FPS entered, defaulting to 60FPS" << std::endl;
		FPS = 60;

	}
		FPS = fps;
}

float EngineTimer::getDelta() {
	return (float)delta;
}
#include "EngineTimer.h"

EngineTimer::EngineTimer(unsigned int fps) {
	FPS = fps;
}

EngineTimer::~EngineTimer() {

}

/*
Calculates number of frames per second (FPS) and milliseconds per frame (ms/frame)
and ouputs them to console
16.6 ms/frame is about 60fps
*/
void EngineTimer::showFPS() {
	double currentTime = glfwGetTime();
	double delta = currentTime - lastTime; //delta is change in time
	numFrames++;// increment frames 
	if (delta >= 1.0) { // If last cout was more than 1 sec ago

		std::cout << "ms/frame: " << 1000.0 / double(numFrames) << std::endl;
		double fps = double(numFrames) / delta;
		std::cout << "FPS: " << fps << std::endl;
		numFrames = 0;
		lastTime = currentTime;
	}
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
	FPS = fps;
}
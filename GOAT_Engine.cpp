#include "GOAT_Engine.h"

GOAT_Engine::GOAT_Engine(int w, int h, const char* title) {
	GLFWwindow* windowTemp;

	/* Initialize the library */
	if (!glfwInit()) {
		std::cout << "GLFW [init] failed!" << std::endl;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	windowTemp = glfwCreateWindow(w, h, title, NULL, NULL);
	if (!windowTemp)
	{
		glfwTerminate();
		std::cout << "Creating window failed!" << std::endl;
	}
	/* Make the window's context current */
	glfwMakeContextCurrent(windowTemp);
	
	

	if (glewInit() != GLEW_OK) {
		std::cout << "Error loading GLEW!" << std::endl;
	}
	std::cout << "OpenGL Version:\n" << glGetString(GL_VERSION) << std::endl << std::endl;

	graphicSource.init();
	graphicSource.addShader("res/shaders/basic.shader");
	this->window = windowTemp;
}

/*
Calculates number of frames per second (FPS) and milliseconds per frame (ms/frame)
and ouputs them to console
16.6 ms/frame is about 60fps
*/
void GOAT_Engine::showFPS() {
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
void GOAT_Engine::limitFPS() {
	//if current frame is rendered and it hasn't been the amount of time for the next frame program will wait
	while (glfwGetTime() < nextFrameTime + 1.0 / maxFPS) {
		//Do nothing
	}
	//set nextFrames time
	nextFrameTime += 1.0 / maxFPS;

}

//sets maximum amount of FPS
void GOAT_Engine::setMaxFPS(double FPS) {
	maxFPS = FPS;
}

GOAT_Engine::~GOAT_Engine() {

}

bool GOAT_Engine::shouldClose() {
	return glfwWindowShouldClose(window);
}

void GOAT_Engine::addSprite(Sprite* sprite) {
	sprites.push_back(sprite);
}

void GOAT_Engine::draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i < sprites.size(); i++) {
		graphicSource.queueSprite(sprites[i]);
	}
	
	graphicSource.draw();
	/* Swap front and back buffers */
	glfwSwapBuffers(window);

	/* Poll for and process events */
	glfwPollEvents();

	limitFPS();
}

void GOAT_Engine::terminate() {
	glfwTerminate();
 }
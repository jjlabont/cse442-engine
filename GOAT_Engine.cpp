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
	
	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK) {
		std::cout << "Error loading GLEW!" << std::endl;
	}
	std::cout << "OpenGL Version:\n" << glGetString(GL_VERSION) << std::endl << std::endl;

	graphicSource.init();
	graphicSource.addShader("res/shaders/basic.shader");
	this->window = windowTemp;
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
}

void GOAT_Engine::terminate() {
	glfwTerminate();
 }
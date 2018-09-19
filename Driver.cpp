#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Graphics.h"

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit()) {
		return -1;
	}
	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(1000, 1000, "GOAT-Engine", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK) {
		std::cout << "Error loading GLEW!" << std::endl;
	}
	std::cout << "OpenGL Version:\n" << glGetString(GL_VERSION) << std::endl << std::endl;

	GraphicSource graphics = GraphicSource();
	graphics.addShader("res/shaders/basic.shader");

	/* Loop until the user closes the window */
	float x = 0;
	while (!glfwWindowShouldClose(window))
	{
		x++;
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		float range = 0.5f;
		float freq = .05f;
		graphics.queueSprite(Sprite(cos(x * freq) * range, sin(x * freq) * range, 0.3f, 0.3f));

		graphics.draw();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}



	glfwTerminate();
	return 0;
}
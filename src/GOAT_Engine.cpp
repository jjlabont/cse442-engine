#include "GOAT_Engine.h"


GOAT_Engine::GOAT_Engine(int w, int h, const char* title, unsigned int fps) {
	timer = EngineTimer(fps);
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
	windowWidth = w;
	windowHeight = h;

	if (glewInit() != GLEW_OK) {
		std::cout << "Error loading GLEW!" << std::endl;
	}
	std::cout << "OpenGL Version:\n" << glGetString(GL_VERSION) << std::endl << std::endl;

	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

	renderer = Renderer();
	shader = new Shader("res/shaders/basic.shader");
	shader->bind();
	shader->setUniform4f("u_Color", 1.0f, 0.5f, 0.25f, 1.0f);

	glm::mat4 proj = glm::ortho(-((float)windowWidth), (float)windowWidth, -((float)windowHeight), (float)windowHeight, -1.0f, 1.0f);
	shader->setUniformMat4f("u_MVP", proj);

	this->window = windowTemp;

	texture = new Texture("res/images/cool uni.png");
	texture->bind();
	shader->setUniform1i("u_Texture", 0);

	input = InputSource(window);
}

GOAT_Engine::~GOAT_Engine() {
	delete shader;
	delete texture;
}

//sets FPS for game to run at
void GOAT_Engine::setFPS(unsigned int fps) {
	timer.setFPS(fps);
}

void GOAT_Engine::toggleDebug() {
	timer.toggleDebug();
}

void GOAT_Engine::draw() {
	if (sprites.size() == 0) {
		renderer.clear();
		glfwSwapBuffers(window);
		glfwPollEvents();
		return;
	}
	std::vector<float> positions;
	std::vector<unsigned int> indices;
	for (int i = 0; i < sprites.size(); i++) {
		//index 0
		positions.push_back(sprites[i]->x);
		positions.push_back(sprites[i]->y);
		positions.push_back(0.0f);
		positions.push_back(0.0f);


		//index 1
		positions.push_back(sprites[i]->x + sprites[i]->w);
		positions.push_back(sprites[i]->y);
		positions.push_back(1.0f);
		positions.push_back(0.0f);


		//index 2
		positions.push_back(sprites[i]->x + sprites[i]->w);
		positions.push_back(sprites[i]->y + sprites[i]->h);
		positions.push_back(1.0f);
		positions.push_back(1.0f);


		//index 3
		positions.push_back(sprites[i]->x);
		positions.push_back(sprites[i]->y + sprites[i]->h);
		positions.push_back(0.0f);
		positions.push_back(1.0f);


		indices.push_back(i * 4 + 0);
		indices.push_back(i * 4 + 1);
		indices.push_back(i * 4 + 2);
		indices.push_back(i * 4 + 2);
		indices.push_back(i * 4 + 3);
		indices.push_back(i * 4 + 0);
	}

	VertexArray va;
	/*
		A = # of indices per sprite
		B = # of values per index
		C = size of float (# of bytes in a float)
		D = # of sprites
		size = ABCD
	*/
	VertexBuffer vb(&positions[0], 4 * 4 * sizeof(float) * sprites.size());

	VertexBufferLayout layout;
	layout.push<float>(2);
	layout.push<float>(2);
	va.addBuffer(vb, layout);

	IndexBuffer ib(&indices[0], 6 * sprites.size());

	renderer.clear();

	renderer.draw(va, ib, *shader);
	
	/* Swap front and back buffers */
	glfwSwapBuffers(window);

	/* Poll for and process events */
	glfwPollEvents();

	timer.update(sprites.size());
}

void GOAT_Engine::addSprite(Sprite* sprite) {
	sprites.push_back(sprite);
}

void GOAT_Engine::pollEvents() {
	input.update();
}

bool GOAT_Engine::shouldClose() {
	return glfwWindowShouldClose(window);
}

void GOAT_Engine::terminate() {
	std::cout << "hi ";
	this->~GOAT_Engine();
	std::cout << "there ";
	glfwTerminate();
	std::cout << "boys ";
 }

InputSource& GOAT_Engine::getInput()
{
	return input;
}

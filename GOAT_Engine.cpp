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
	
	

	if (glewInit() != GLEW_OK) {
		std::cout << "Error loading GLEW!" << std::endl;
	}
	std::cout << "OpenGL Version:\n" << glGetString(GL_VERSION) << std::endl << std::endl;

	renderer = Renderer();
	shader = new Shader("res/shaders/basic.shader");
	shader->bind();
	shader->setUniform4f("u_Color", 1.0f, 0.5f, 0.25f, 1.0f);
	shader2 = new Shader("res/shaders/basic.shader");
	shader2->bind();
	shader2->setUniform4f("u_Color", 1.0f, 1.0f, 0.25f, 1.0f);

	this->window = windowTemp;
}

GOAT_Engine::~GOAT_Engine() {
	delete shader;
}

bool GOAT_Engine::shouldClose() {
	return glfwWindowShouldClose(window);
}

void GOAT_Engine::addSprite(Sprite* sprite) {
	sprites.push_back(sprite);
}

//displays FPS to console
void GOAT_Engine::showFPS() {
	timer.showFPS();
}

//sets FPS for game to run at
void GOAT_Engine::setFPS(unsigned int fps) {
	timer.setFPS(fps);
}

void GOAT_Engine::draw() {
	std::vector<float> positions;
	std::vector<unsigned int> indices;
	for (int i = 0; i < sprites.size(); i++) {
		//index 0
		positions.push_back(sprites[i]->x);
		positions.push_back(sprites[i]->y);

		//index 1
		positions.push_back(sprites[i]->x + sprites[i]->w);
		positions.push_back(sprites[i]->y);

		//index 2
		positions.push_back(sprites[i]->x + sprites[i]->w);
		positions.push_back(sprites[i]->y + sprites[i]->h);

		//index 3
		positions.push_back(sprites[i]->x);
		positions.push_back(sprites[i]->y + sprites[i]->h);

		indices.push_back(i * 4 + 0);
		indices.push_back(i * 4 + 1);
		indices.push_back(i * 4 + 2);
		indices.push_back(i * 4 + 2);
		indices.push_back(i * 4 + 3);
		indices.push_back(i * 4 + 0);
	}

	VertexArray va;
	VertexBuffer vb(&positions[0], 4 * 2 * sizeof(float) * sprites.size());

	VertexBufferLayout layout;
	layout.push<float>(2);
	va.addBuffer(vb, layout);

	IndexBuffer ib(&indices[0], 6 * sprites.size());

	renderer.clear();

	renderer.draw(va, ib, *shader);
	
	/* Swap front and back buffers */
	glfwSwapBuffers(window);

	/* Poll for and process events */
	glfwPollEvents();

	timer.limitFPS();
}

void GOAT_Engine::terminate() {
	glfwTerminate();
 }
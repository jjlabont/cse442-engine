#pragma once
//resource includes
#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"

//goat engine headers
#include "Input/Input.h"
#include "Util/EngineTimer.h"
#include "Graphics/Graphics.h"
#include "Graphics/Texture/Texture.h"
#include "Objects/Entity/Entity.h"

class GOAT_Engine {
private:
	bool show_demo_window;
	bool show_another_window;
	ImVec4 clear_color;

	GLFWwindow* window;
	EngineTimer timer;

	Renderer renderer;
	Shader* shader;

	std::vector<Sprite*> sprites;
	std::vector<Entity*> entities;
	Texture* texture;

	unsigned int windowWidth;
	unsigned int windowHeight;
	InputSource input;
public:


	GOAT_Engine(int w, int h, const char* title, unsigned int fps = 60);
	~GOAT_Engine();

	void toggleDebug();

	void setFPS(unsigned int fps);

	void draw();
	void addSprite(Sprite* sprite);
	void addEntity(Entity* entity);

	void pollEvents();

	bool shouldClose();
	void terminate();

	InputSource& getInput();
};
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(glLogCall(#x, __FILE__, __LINE__))

static void GLClearError() {
	while (glGetError() != GL_NO_ERROR);
}

static bool glLogCall(const char* function, const char* file, int line) {
	while (GLenum error = glGetError()) {
		std::cout << "[OpenGL Error " << "(" << error << ")]: "
			<< function << " " << file << ":" << line << std::endl;
		return false;
	}
	return true;
}

static unsigned int compileShader(unsigned int type, const std::string& source) {
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);

		std::cout << "Failed to compile Shader:\n" << message << std::endl;
		glDeleteShader(id);
		return 0;
	}

	return id;
}

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {
	unsigned int program = glCreateProgram();
	unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

struct Sprite {
	Sprite(float x, float y, float w, float h) {
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
		
		rotation = 0;
	}
	float x, y, w, h;
	float rotation;
};

struct ShaderProgramSource {
	ShaderProgramSource(const std::string& filepath);

	std::string vSource;
	std::string fSource;
};

class GraphicSource {
private:
	unsigned int vao;
	unsigned int vbo;
	unsigned int ibo;
	unsigned int colorLocation;
	
	std::vector<Sprite*> drawBatch;
	std::vector<unsigned int> shader;

public:
	float r;
	float g;
	float b;
	float a;
	GraphicSource();
	~GraphicSource();

	void init();

	void addShader(const std::string& filepath);

	void queueSprite(Sprite* sprite);
	void draw();
};
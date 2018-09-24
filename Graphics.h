#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "Shader.h"

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(glLogCall(#x, __FILE__, __LINE__))
void GLClearError();
bool glLogCall(const char* function, const char* file, int line);

unsigned int compileShader(unsigned int type, const std::string& source);
unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

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

class VertexBuffer {
private:
	unsigned int m_RendererID;
public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void bind() const;
	void unbind() const;
};

struct VertexBufferElement {
	unsigned int count;
	unsigned int type;
	unsigned char normalized;

	static unsigned int getSizeOfType(unsigned int type) {
		switch (type)
		{
			case GL_FLOAT:			return 4;
			case GL_UNSIGNED_INT:	return 4;
			case GL_UNSIGNED_BYTE:	return 1;
		} 

		ASSERT(false);
		return 0;
	}
};

class VertexBufferLayout {
private:
	std::vector<VertexBufferElement> m_Elements;
	unsigned int m_Stride;
public:
	VertexBufferLayout() : m_Stride(0) {

	}

	template<typename T>
	void push(unsigned int count) {
		static_assert(false);
	}

	template<>
	void push<float>(unsigned int count) {
		m_Elements.push_back({ GL_FLOAT, count, GL_FALSE });
		m_Stride += count * VertexBufferElement::getSizeOfType(GL_FLOAT);
	}

	template<>
	void push<unsigned int>(unsigned int count) {
		m_Elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
		m_Stride += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_INT);
	}

	template<>
	void push<unsigned char>(unsigned int count) {
		m_Elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
		m_Stride += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_BYTE);
	}

	inline const std::vector<VertexBufferElement> GetElements() const { return m_Elements; }
	inline unsigned int getStride() const { return m_Stride; }
};

class IndexBuffer {
private:
	unsigned int m_RendererID;
	unsigned int m_Count;
public: 
	IndexBuffer(const unsigned int* data, unsigned int count);
	~IndexBuffer();

	void bind() const;
	void unbind() const;

	inline unsigned int getCount() const { return m_Count; }
};

class VertexArray {
private:
	unsigned int m_RendererID;
public:
	VertexArray();
	~VertexArray();

	void addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

	void bind() const;
	void unbind() const;
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
/*
class Renderer {
private:

public:
	Renderer();
	~Renderer();
	void draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};*/
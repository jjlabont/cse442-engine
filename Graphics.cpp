#pragma once
#include "Graphics.h"

void GLClearError() {
	while (glGetError() != GL_NO_ERROR);
}

bool glLogCall(const char* function, const char* file, int line) {
	while (GLenum error = glGetError()) {
		std::cout << "[OpenGL Error " << "(" << error << ")]: "
			<< function << " " << file << ":" << line << std::endl;
		return false;
	}
	return true;
}

unsigned int compileShader(unsigned int type, const std::string& source) {
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

unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {
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

//-----------------------------------------------------------------------------
//	SHADER CLASS
//-----------------------------------------------------------------------------
ShaderProgramSource::ShaderProgramSource(const std::string& filepath) {
	//file stream of shader file
	std::ifstream stream(filepath);

	//which shader in the file we are currently looking at
	enum class ShaderType {
		NONE = -1,
		VERTEX = 0,
		FRAGMENT = 1
	};


	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;
	//parse vs into ss[0], fs into ss[1]
	while (getline(stream, line)) {
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos) {
				type = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos) {
				type = ShaderType::FRAGMENT;
			}
		}
		else {
			ss[(int)type] << line << '\n';
		}
	}

	vSource = ss[0].str();
	fSource = ss[1].str();
}

//-----------------------------------------------------------------------------
//	VERTEX BUFFER CLASS
//-----------------------------------------------------------------------------
VertexBuffer::VertexBuffer(const void* data, unsigned int size) {
	GLCall(glGenBuffers(1, &m_RendererID));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer() {
	GLCall(glDeleteBuffers(1, &m_RendererID));
}

void VertexBuffer::bind() const {
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}

void VertexBuffer::unbind() const {
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

//-----------------------------------------------------------------------------
//	INDEX BUFFER CLASS
//-----------------------------------------------------------------------------
IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count) {
	m_Count = count;
	GLCall(glGenBuffers(1, &m_RendererID));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer() {
	GLCall(glDeleteBuffers(1, &m_RendererID));
}

void IndexBuffer::bind() const {
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
}

void IndexBuffer::unbind() const {
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

//-----------------------------------------------------------------------------
//	VERTEX ARRAY CLASS
//-----------------------------------------------------------------------------
VertexArray::VertexArray() {
	GLCall(glGenVertexArrays(1, &m_RendererID));
}

VertexArray::~VertexArray() {
	GLCall(glDeleteVertexArrays(1, &m_RendererID));
}

void VertexArray::addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) {
	bind();
	vb.bind();
	const auto& elements = layout.GetElements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++) {
		const auto& element = elements[i];
		GLCall(glEnableVertexAttribArray(i));
		GLCall(glVertexAttribPointer(i, element.count, element.type,
									 element.normalized, layout.getStride(), 0));
		offset += element.count * VertexBufferElement::getSizeOfType(element.type);
	}
}

void VertexArray::bind() const {
	GLCall(glBindVertexArray(m_RendererID));
}

void VertexArray::unbind() const {
	GLCall(glBindVertexArray(0));
}

//-----------------------------------------------------------------------------
//	GRAPHIC SOURCE CLASS
//-----------------------------------------------------------------------------
GraphicSource::GraphicSource() {

}

GraphicSource::~GraphicSource() {
	for (int i = 0; i < shader.size(); i++) {
		GLCall(glDeleteProgram(shader[i]));
	}
}

void GraphicSource::init() {
	//vao
	GLCall(glGenVertexArrays(1, &vao));
	GLCall(glBindVertexArray(vao));

	//vbo
	vbo = 0;
	GLCall(glGenBuffers(1, &vbo));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, vbo));

	GLCall(glEnableVertexAttribArray(0));
	GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0));

	//ibo
	ibo = 0;
	GLCall(glGenBuffers(1, &ibo));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
}

void GraphicSource::addShader(const std::string& filepath) {
	ShaderProgramSource source = ShaderProgramSource(filepath);
	shader.push_back(CreateShader(source.vSource, source.fSource));
	GLCall(glUseProgram(shader[0]));

	GLCall(colorLocation = glGetUniformLocation(shader[0], "u_Color"));
	ASSERT(colorLocation != -1);
	GLCall(glUniform4f(colorLocation, 0.2f, 0.3f, 0.8f, 1.0f));
}

void GraphicSource::queueSprite(Sprite* sprite) {
	drawBatch.push_back(sprite);
}

void GraphicSource::draw() {
	if (drawBatch.size() == 0) {
		return;
	}

	std::vector<float> positions;
	std::vector<unsigned int> indicies;
	for (unsigned int i = 0; i < drawBatch.size(); i++) {

		//index 0
		positions.push_back(drawBatch[i]->x);
		positions.push_back(drawBatch[i]->y);

		//index 1
		positions.push_back(drawBatch[i]->x + drawBatch[i]->w);
		positions.push_back(drawBatch[i]->y);

		//index 2
		positions.push_back(drawBatch[i]->x + drawBatch[i]->w);
		positions.push_back(drawBatch[i]->y + drawBatch[i]->h);

		//index 3
		positions.push_back(drawBatch[i]->x);
		positions.push_back(drawBatch[i]->y + drawBatch[i]->h);

		indicies.push_back(i * 4 + 0);
		indicies.push_back(i * 4 + 1);
		indicies.push_back(i * 4 + 2);
		indicies.push_back(i * 4 + 2);
		indicies.push_back(i * 4 + 3);
		indicies.push_back(i * 4 + 0);
	}
	
	unsigned int numSprites = drawBatch.size();
	GLCall(glBufferData(GL_ARRAY_BUFFER, numSprites * 4 * 2 * sizeof(float), &positions[0], GL_STATIC_DRAW));
 

	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, numSprites * 6 * sizeof(unsigned int), &indicies[0], GL_STATIC_DRAW));
	GLCall(glUniform4f(colorLocation, r, g, b, a));
	GLCall(glDrawElements(GL_TRIANGLES, 6 * numSprites, GL_UNSIGNED_INT, nullptr));

	drawBatch.clear();
}

//-----------------------------------------------------------------------------
//	GRAPHIC SOURCE CLASS
//-----------------------------------------------------------------------------
/*
Renderer::Renderer() {

}

Renderer::~Renderer() {

}

void Renderer::draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const {
	shader.bind();
	va.bind();
	ib.bind();
	GLCall(glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, nullptr));
}
*/
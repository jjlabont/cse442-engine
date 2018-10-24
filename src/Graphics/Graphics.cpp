#pragma once
#include "Graphics.h"

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
									 element.normalized, layout.getStride(), (const void*)offset));
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
//	RENDERER CLASS
//-----------------------------------------------------------------------------

Renderer::Renderer() {

}

Renderer::~Renderer() {

}

void Renderer::clear() const {
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const {
	shader.bind();
	va.bind();
	ib.bind();
	GLCall(glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, nullptr));
}
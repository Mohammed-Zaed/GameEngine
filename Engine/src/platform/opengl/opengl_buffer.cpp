#include "precompiled.h"
#include "glad/glad.h"
#include "opengl_buffer.h"

Engine::OpenglVertexBuffer::OpenglVertexBuffer(float *vertices, uint32_t size)
{
	glCreateBuffers(1, &m_rendererId);
	glBindBuffer(GL_ARRAY_BUFFER, m_rendererId);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void Engine::OpenglVertexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_rendererId);

}

void Engine::OpenglVertexBuffer::unBind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Engine::OpenglVertexBuffer::~OpenglVertexBuffer()
{
	glDeleteBuffers(1, &m_rendererId);
}


Engine::OpenglIndexBuffer::OpenglIndexBuffer(uint32_t* indices, uint32_t count)
{
	glCreateBuffers(1, &m_rendererId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);

}

void Engine::OpenglIndexBuffer::bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererId);
}

void Engine::OpenglIndexBuffer::unBind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

Engine::OpenglIndexBuffer::~OpenglIndexBuffer()
{
	glDeleteBuffers(1, &m_rendererId);
}

#include "precompiled.h"
#include "buffer.h"
#include "renderer.h"
#include "platform/opengl/opengl_buffer.h"

namespace Engine {

    VertexBuffer* VertexBuffer::create(float* vertices, uint32_t size)
    {
		switch (Renderer::getAPI())
		{
		case RendererAPI::None:    ENGINE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::OpenGL:  return new OpenglVertexBuffer(vertices, size);
		}

        ENGINE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    IndexBuffer* IndexBuffer::create(uint32_t* indices, uint32_t count)
    {
		switch (Renderer::getAPI())
		{
		case RendererAPI::None:    ENGINE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::OpenGL:  return new OpenglIndexBuffer(indices, count);
		}

		ENGINE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}

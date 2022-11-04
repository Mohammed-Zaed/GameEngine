#pragma once
#include "precompiled.h"

namespace Engine {

	class VertexBuffer 
	{
	public:
		virtual ~VertexBuffer() {}

		virtual void bind() const = 0;
		virtual void unBind() const = 0;

		static VertexBuffer* create(float* vertices, uint32_t size);

	};

	class IndexBuffer 
	{
	public:
		virtual ~IndexBuffer() {}

		virtual void bind() const = 0;
		virtual void unBind() const = 0;

		static IndexBuffer* create(uint32_t* indices, uint32_t count);
	};
	
}

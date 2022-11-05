#pragma once
#include "precompiled.h"
#include "renderer/buffer.h"

namespace Engine
{
	class OpenglVertexBuffer:public VertexBuffer
	{
	public:
		OpenglVertexBuffer(float *vertices, uint32_t size);
		~OpenglVertexBuffer();

		virtual void bind() const override;
		virtual void unBind() const override;

		virtual const BufferLayout& getLayout() const override { return m_layout; }
		virtual void setLayout(const BufferLayout& layout) override { m_layout = layout; }

	private:
		uint32_t m_rendererId;
		BufferLayout m_layout;

	};

	class OpenglIndexBuffer: public IndexBuffer
	{
	public:
		OpenglIndexBuffer(uint32_t* indices, uint32_t count);
		virtual ~OpenglIndexBuffer();

		virtual void bind() const override;
		virtual void unBind() const override;
		virtual uint32_t getCount() const { return m_count; }

	private:
		uint32_t m_rendererId;
		uint32_t m_count;
	};
}
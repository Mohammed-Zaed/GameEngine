#pragma once

#include "precompiled.h"
#include "renderer/graphics_context.h"

struct GLFWwindow;

namespace Engine {

	class OpenglContext : public GraphicsContext
	{

	public:
		OpenglContext(GLFWwindow* windowHandle);

		virtual void init();
		virtual void swapBuffers();
	private:
		GLFWwindow* m_windowHandle;
	};
}
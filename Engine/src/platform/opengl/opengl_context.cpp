#include "precompiled.h"
#include "opengl_context.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace Engine {

	OpenglContext::OpenglContext(GLFWwindow* windowHandle)
		: m_windowHandle(windowHandle)
	{
		ENGINE_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenglContext::init()
	{
		glfwMakeContextCurrent(m_windowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ENGINE_CORE_ASSERT(status, "Failed to initialize Glad!");
	}

	void OpenglContext::swapBuffers()
	{
		glfwSwapBuffers(m_windowHandle);
	}

}
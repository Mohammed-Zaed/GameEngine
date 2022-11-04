#include "precompiled.h"
#include "application.h"
#include "events/app_event.h"
#include "events/event.h"
#include "core/log.h"
#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "imgui/imguilayer.h"

namespace Engine
{
	Application* Application::m_instance = nullptr;

	Application::Application()
	{
		m_instance = this;
		m_window = std::unique_ptr<Window>(Window::create());
		m_window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));

		m_imGuiLayer = new ImGuiLayer();
		pushOverlay(m_imGuiLayer);

		float vertices[3 * 3] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

		m_vertexBuffer.reset(VertexBuffer::create(vertices, sizeof(vertices)));


		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		uint32_t indices[3] = { 0, 1, 2 };
		m_indexBuffer.reset(IndexBuffer::create(indices, sizeof(indices) / sizeof(uint32_t)));


		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			out vec3 v_Position;
			void main()
			{
				v_Position = a_Position;
				gl_Position = vec4(a_Position, 1.0);	
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
			}
		)";

		m_shader.reset(new Shader(vertexSrc, fragmentSrc));
	}

	Application::~Application()
	{

	}

	void Application::run()
	{
		WindowResizeEvent  windowResizeEvent(1280, 720);

		while (m_running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			m_shader->bind();
			glBindVertexArray(m_vertexArray);
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

			for (Layer* layer : m_layerStack)
				layer->onUpdate();

			m_imGuiLayer->begin();
			for (Layer* layer : m_layerStack)
				layer->onImGuiRender();
			m_imGuiLayer->end();

			m_window->onUpdate();

		}
	}

	void Application::onEvent(Event& event)
	{
		EventDispatcher eventDispatcher(event);
		eventDispatcher.dispatch<WindowCloseEvent>(std::bind(&Application::onWindowClose, this, std::placeholders::_1));
		ENGINE_CORE_TRACE("{0}", event);

		for (auto it = m_layerStack.end(); it != m_layerStack.begin(); )
		{
			(*--it)->onEvent(event);
			if (event.isHandled())
			{
				break;
			}
		}
	}

	void Application::pushLayer(Layer* layer)
	{
		m_layerStack.pushLayer(layer);
	}

	void Application::pushOverlay(Layer* overlay)
	{
		m_layerStack.pushOverlay(overlay);
	}

	bool Application::onWindowClose(WindowCloseEvent& event)
	{
		m_running = false;
		return true;
	}
}
#include <engine.h>

class ExampleLayer : public Engine::Layer
{
public:
	ExampleLayer()
		:Layer("Example Layer")
	{

	}

	virtual void onUpdate() override
	{

	}

	virtual void onEvent(Engine::Event& event) override
	{
		ENGINE_TRACE("{0}", event);
	}


};

class Sandbox : public Engine::Application
{
public:
	Sandbox()
	{
		pushLayer(new ExampleLayer());
		pushOverlay(new Engine::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Engine::Application* Engine::createApplication()
{
	return new Sandbox();
}
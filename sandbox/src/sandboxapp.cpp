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
		if (Engine::Input::isKeyPressed(ENGINE_KEY_TAB))
		{
			ENGINE_TRACE("Tab key is pressed (poll)!");
		}

	}

	virtual void onEvent(Engine::Event& event) override
	{
		if (event.getType() == Engine::EventType::KEY_PRESS_EVENT)
		{
			Engine::KeyPressedEvent& e = (Engine::KeyPressedEvent&)event;
			if (e.getKeyCode() == ENGINE_KEY_TAB)
				ENGINE_TRACE("Tab key is pressed (event)!");
			ENGINE_TRACE("{0}", (char)e.getKeyCode());
		}
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
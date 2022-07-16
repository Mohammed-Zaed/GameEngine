#pragma once
#ifdef ENGINE_WINDOWS
extern Engine::Application* Engine::createApplication();
int main(int argc, char** argv)
{
	std::cout << "Engine::Entrypoint" << std::endl;
	auto app = Engine::createApplication();
	app->run();
	delete app;
	return 0;
}
#else
#error Engine supports only windows.
#endif

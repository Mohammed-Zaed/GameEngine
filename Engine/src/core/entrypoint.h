#pragma once

#ifdef ENGINE_WINDOWS
extern Engine::Application* Engine::createApplication();
int main(int argc, char** argv)
{
	Engine::Log::init();
	
	ENGINE_CORE_ERROR("CORE ERROR");
	ENGINE_ERROR("APP ERROR");

	std::cout << "Engine::Entrypoint" << std::endl;
	auto app = Engine::createApplication();
	app->run();
	delete app;
	return 0;
}
#else
	#error Engine supports only windows.
#endif



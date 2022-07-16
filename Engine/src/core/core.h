#pragma once

#ifdef ENGINE_WINDOWS
	#ifdef BUILD_DLL
		#define ENGINE_API __declspec(dllexport)
	#else
		#define ENGINE_API __declspec(dllimport)
	#endif
#else
	#error Engine supports only windows.
#endif

#define ENGINE_CORE_FATAL(...)	Engine::Log::getCoreLogger()->fatal(__VA_ARGS__)
#define ENGINE_CORE_ERROR(...)	Engine::Log::getCoreLogger()->error(__VA_ARGS__)
#define ENGINE_CORE_WARN(...)	Engine::Log::getCoreLogger()->warn(__VA_ARGS__)
#define ENGINE_CORE_INFO(...)	Engine::Log::getCoreLogger()->info(__VA_ARGS__)
#define ENGINE_CORE_TRACE(...)	Engine::Log::getCoreLogger()->trace(__VA_ARGS__)

#define ENGINE_FATAL(...)		Engine::Log::getClientLogger()->fatal(__VA_ARGS__)
#define ENGINE_ERROR(...)		Engine::Log::getClientLogger()->error(__VA_ARGS__)
#define ENGINE_WARN(...)		Engine::Log::getClientLogger()->warn(__VA_ARGS__)
#define ENGINE_INFO(...)		Engine::Log::getClientLogger()->info(__VA_ARGS__)
#define ENGINE_TRACE(...)		Engine::Log::getClientLogger()->trace(__VA_ARGS__)


#include <iostream>
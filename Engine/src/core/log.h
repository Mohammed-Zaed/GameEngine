#pragma once
#include "precompiled.h"
#include "core.h"
#include "spdlog/spdlog.h"
#include "Spdlog/fmt/ostr.h"

namespace Engine
{
	class ENGINE_API Log  
	{
	public:

		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return m_coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return m_clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> m_coreLogger;
		static std::shared_ptr<spdlog::logger> m_clientLogger;
	};
}


#define ENGINE_CORE_FATAL(...)	::Engine::Log::getCoreLogger()->fatal(__VA_ARGS__)
#define ENGINE_CORE_ERROR(...)	::Engine::Log::getCoreLogger()->error(__VA_ARGS__)
#define ENGINE_CORE_WARN(...)	::Engine::Log::getCoreLogger()->warn(__VA_ARGS__)
#define ENGINE_CORE_INFO(...)	::Engine::Log::getCoreLogger()->info(__VA_ARGS__)
#define ENGINE_CORE_TRACE(...)	::Engine::Log::getCoreLogger()->trace(__VA_ARGS__)

#define ENGINE_FATAL(...)		::Engine::Log::getClientLogger()->fatal(__VA_ARGS__)
#define ENGINE_ERROR(...)		::Engine::Log::getClientLogger()->error(__VA_ARGS__)
#define ENGINE_WARN(...)		::Engine::Log::getClientLogger()->warn(__VA_ARGS__)
#define ENGINE_INFO(...)		::Engine::Log::getClientLogger()->info(__VA_ARGS__)
#define ENGINE_TRACE(...)		::Engine::Log::getClientLogger()->trace(__VA_ARGS__)


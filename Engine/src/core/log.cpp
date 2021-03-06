#include "precompiled.h"
#include "log.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Engine
{
	std::shared_ptr<spdlog::logger> Log::m_coreLogger;
	std::shared_ptr<spdlog::logger> Log::m_clientLogger;

	void Log::init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		
		m_coreLogger = spdlog::stdout_color_mt("ENGINE");
		m_coreLogger->set_level(spdlog::level::trace);

		m_clientLogger = spdlog::stdout_color_mt("APP");
		m_clientLogger->set_level(spdlog::level::trace);
	}
}
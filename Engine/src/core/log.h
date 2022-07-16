#pragma once
#include <memory>
#include "core.h"
#include "spdlog/spdlog.h"

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

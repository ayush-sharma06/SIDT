#pragma once


#include "Core.h"
#include "spdlog/spdlog.h"

namespace SIDT {
	class SIDT_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log Macros
#define SD_CORE_TRACE(...) SIDT::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SD_CORE_INFO(...) SIDT::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SD_CORE_WARN(...) SIDT::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SD_CORE_CRITICAL(...) SIDT::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define SD_CORE_DEBUG(...) SIDT::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define SD_CORE_ERROR(...) SIDT::Log::GetCoreLogger()->error(__VA_ARGS__)

// Client Log Macros
#define SD_TRACE(...) SIDT::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SD_INFO(...) SIDT::Log::GetClientLogger()->info(__VA_ARGS__)
#define SD_WARN(...) SIDT::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SD_CRITICAL(...) SIDT::Log::GetClientLogger()->critical(__VA_ARGS__)
#define SD_DEBUG(...) SIDT::Log::GetClientLogger()->debug(__VA_ARGS__)
#define SD_ERROR(...) SIDT::Log::GetClientLogger()->error(__VA_ARGS__)
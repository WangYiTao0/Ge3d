#pragma once

#include "GE/Core/Base.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Ge {

	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define GE_CORE_TRACE(...)    ::Ge::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GE_CORE_INFO(...)     ::Ge::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GE_CORE_WARN(...)     ::Ge::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GE_CORE_ERROR(...)    ::Ge::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GE_CORE_CRITICAL(...) ::Ge::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define GE_TRACE(...)         ::Ge::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GE_INFO(...)          ::Ge::Log::GetClientLogger()->info(__VA_ARGS__)
#define GE_WARN(...)          ::Ge::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GE_ERROR(...)         ::Ge::Log::GetClientLogger()->error(__VA_ARGS__)
#define GE_CRITICAL(...)      ::Ge::Log::GetClientLogger()->critical(__VA_ARGS__)
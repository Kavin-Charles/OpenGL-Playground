#pragma once

#include <memory>
#include "Core.h"
#define FMT_UNICODE 0
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace GameEngine {

	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_CoreLogger; }

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		
	};

}

#define CORE_TRACE(...)    ::GameEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CORE_INFO(...)     ::GameEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CORE_WARN(...)     ::GameEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CORE_ERROR(...)    ::GameEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CORE_FATAL(...)    ::GameEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define CLIENT_TRACE(...)	       ::GameEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CLIENT_INFO(...)	       ::GameEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define CLIENT_WARN(...)	       ::GameEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CLIENT_ERROR(...)	       ::GameEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define CLIENT_FATAL(...)	       ::GameEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)
// For now we have only added windows support for our SIDT as we verify if SD_PLATFORM_WINDOWS is defined




#pragma once


#ifdef SD_PLATFORM_WINDOWS
#ifdef SD_BUILD_DLL
#define SIDT_API __declspec(dllexport)
#else
#define SIDT_API __declspec(dllimport)
#endif
#else
#error "SIDT only support Windows!"
#endif

#define BIT(x) (1<<x)

#ifdef SD_ENABLE_ASSERT
#define SD_ASSERT(x, ...) {if(!x) {SD_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak;}}
#define SD_CORE_ASSERT(x, ...) {if(!x) {SD_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak;}}
#else
#define SD_ASSERT(x, ...)
#define SD_CORE_ASSERT(x, ...)
#endif

#define SD_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
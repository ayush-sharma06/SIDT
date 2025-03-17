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
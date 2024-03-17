#pragma once
#include <string>

#ifdef LEAVER_EXPORTS
#define LEAVERAPI_API __declspec(dllexport)
#else
#define LEAVERAPI_API __declspec(dllimport)
#endif

namespace DynamicLibrary
{
	class Leaver {
	public:
		LEAVERAPI_API void leave(std::string n);
	};
}
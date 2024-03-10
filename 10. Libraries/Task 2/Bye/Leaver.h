#include <string>
#pragma once
#ifdef DYNAMICLIBRARY_EXPORTS
#define DYNAMICLIBRARY_API __declspec(dllexport)
#else 
#define DYNAMICLIBRARY_API __declspec(dllimport)
#endif 
namespace DynamicLibrary
{
	 class Leaver {
	public:
		DYNAMICLIBRARY_API void leave(std::string name);
	};
}
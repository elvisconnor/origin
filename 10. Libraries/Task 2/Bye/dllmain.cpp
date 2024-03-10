#include "Leaver.h"
#include <iostream>
#include <string>

namespace DynamicLibrary
{
	void Leaver::leave(std::string name) {
		std::cout << "До свидания, " << name << "!\n";
	}
}
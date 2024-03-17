#include "Leaver.h"
#include <iostream>
#include <string>

namespace DynamicLibrary
{
	void Leaver::leave(std::string n) {
		std::cout << "До свидания, " << n << "!\n";
	}
}
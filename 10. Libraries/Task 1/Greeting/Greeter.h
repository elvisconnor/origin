#pragma once
#include <string>

class Greeter {
	std::string name;
public:
	Greeter(std::string name);
	void greet();
};

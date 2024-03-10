#include <iostream>
#include <string>
#include "Greeter.h"

Greeter::Greeter(std::string name) {
	this->name = name;
}

void Greeter::greet() {
	std::cout << "Здравствуйте, " << name << "!\n";
}
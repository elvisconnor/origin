#pragma once

#include <iostream>
#include <string>

class Exceptions : public std::domain_error {
	std::string message;
public:
	Exceptions(const std::string &message);
	const char* what() const noexcept;
};

#include "exceptions.h"
#include <string>

Exceptions::Exceptions(const std::string& message) : std::domain_error(message) {
	this->message = message;
};
const char* Exceptions::what() const noexcept {
	return message.c_str();
}
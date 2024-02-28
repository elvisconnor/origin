#include <iostream>
#include <string>

int main() {
	setlocale(0, "");

	std::string name = "";

	std::cout << "Введите имя: ";
	std::cin >> name;
	std::cout << "Здравствуйте, " << name << "!";


	return 0;
}
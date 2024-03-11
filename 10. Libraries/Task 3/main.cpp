#include <iostream>
#include <string>
#include "Leaver.h"

int main()
{
    std::string name = "";
    std::cout << "Введите имя: ";
    std::cin >> name;
    DynamicLibrary::Leaver bye;
    bye.leave(name);
}
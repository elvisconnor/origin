#include <iostream>
#include <string>

#include "Greeter.h"

int main()
{
    setlocale(0, "");
    std::string name = "";
    std::cout << "Введите имя: ";
    std::cin >> name;

    Greeter f1(name);
    f1.greet();
}
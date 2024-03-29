﻿#include <iostream>
#include <string>
#include "Counter.h"

int main()
{
    setlocale(0, "");
    std::string choice;
    int init_num = 0;
    std::string command;

    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> choice;

    while (choice == "да") {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> init_num;
        Counter cnt(init_num);

        while (true) {
            std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
            std::cin >> command;

            if (command == "+") {
                cnt.plus();
            }
            else if (command == "-") {
                cnt.minus();
            }
            else if (command == "=") {
                cnt.show();
            }
            else {
                std::cout << "До свидания!";
                break;
            }
        }
        break;
    }

    while (choice == "нет") {
        Counter cnt;

        while (true) {
            std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
            std::cin >> command;

            if (command == "+") {
                cnt.plus();
            }
            else if (command == "-") {
                cnt.minus();
            }
            else if (command == "=") {
                cnt.show();
            }
            else {
                std::cout << "До свидания!";
                break;
            }
        }
        break;
    }
    return 0;
}
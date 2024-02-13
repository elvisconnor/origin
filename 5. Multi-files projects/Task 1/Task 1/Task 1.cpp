#include <iostream>
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include "Exponent.h"

int main()
{
    setlocale(0, "");
    int num1 = 0, num2 = 0, choice = 0;

    std::cout << "Введите первое число: ";
    std::cin >> num1;

    std::cout << "Введите второе число: ";
    std::cin >> num2;

    std::cout << "Выберите операцию (1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
    std::cin >> choice;

    if (choice == 1) {
        std::cout << num1 << " + " << num2 << " = " << addition(num1, num2);
    }
    else if (choice == 2) {
        std::cout << num1 << " - " << num2 << " = " << subtraction(num1, num2);
    }
    else if (choice == 3) {
        std::cout << num1 << " * " << num2 << " = " << multiplication(num1, num2);
    }
    else if (choice == 4) {
        std::cout << num1 << " / " << num2 << " = " << division(num1, num2);
    }
    else if (choice == 5) {
        if (num2 == 0) {
            std::cout << num1 << " в степени " << num2 << " = " << 0;
        }
        else {
            std::cout << num1 << " в степени " << num2 << " = " << exponention(num1, num2);
        }
    }
     
    return 0;
}
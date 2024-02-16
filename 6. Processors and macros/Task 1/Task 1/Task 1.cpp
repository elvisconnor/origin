#include <iostream>

#define MODE 1 

int main()
{
    setlocale(0, "");

#ifndef MODE
#error Необходимо определить константу MODE
#endif

#ifdef MODE
#if MODE == 0
    std::cout << "Работаю в режиме тренировки\n";
#elif MODE == 1
#define add(x, y) (x) + (y)
    int x = 0, y = 0;

    std::cout << "Работаю в боевом режиме\n";
    std::cout << "Введите число 1: ";
    std::cin >> x;
    std::cout << "Введите число 2: ";
    std::cin >> y;
    std::cout << "Результат сложения: " << add(x, y);
#else 
    std::cout << "Неизвестный режим. Завершение работы";
#endif
#endif
}
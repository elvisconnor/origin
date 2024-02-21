#include "Figure.h"
#include <iostream>

Figure::Figure() {
        this->name = "Фигура";
    };
void Figure::print_info() {
    std::cout << name << ": \n";
}

void Figure::print_in_one_line() {};
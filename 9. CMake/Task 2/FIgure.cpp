#include "Figure.h"
#include <iostream>

Figure::Figure() {
        this->name = "Фигура";
    };
void Figure::print_info(){
        std::cout << name << ": \n";
    }
#include <iostream>
#include <string>
#include "Figure.h"
#include "Triangle.h"
#include "IsoscelesTriangle.h"
#include "RightTriangle.h"
#include "Eq_triangle.h"
#include "Quad.h"
#include "Rectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhombus.h"

//Функция вывода информации
void print(Figure* figure) {
    figure->print_info();
}

int main() {
    Triangle trngl(10, 20, 30, 25, 35, 45);
    RightTriangle right_trngl(66, 77, 88, 32, 45);
    IsoscelesTriangle iso_trngl(10, 20, 30, 45);
    Eq_triangle eq_trngl(10);

    Quad quad1(10, 20, 30, 40, 90, 90, 90, 90);
    Rectangle rctng1(35, 78, 65, 23);
    Square sqr1(10);
    Parallelogram prlgm1(10, 20, 40, 60);
    Rhombus rmbs1(10, 45, 45);

    Figure** figures = new Figure * [9] {
        &trngl, & right_trngl, & iso_trngl, & eq_trngl, & quad1, & rctng1, & sqr1, & prlgm1, & rmbs1
        };

    for (int i = 0; i < 9; i++) {
        print(figures[i]);
    };

    delete[] figures;

    return 0;
}
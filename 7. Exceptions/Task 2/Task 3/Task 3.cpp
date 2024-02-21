#include <iostream>
#include <string>
#include "Exceptions.h"
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

void print(Figure* figure) {
    figure->print_info();
}

int main() {
    
    // Треугольник НЕ будет создан - сумма углов больше 180
    try {
        Triangle trngl(10, 20, 30, 555, 30, 45);
        trngl.print_in_one_line();
    }
    catch (Exceptions& ex) {
        std::cout << ex.what() << std::endl;
    }

    // Прямоугольный треугольник будет создан - все ок
    try {
        RightTriangle right_trngl(10, 20, 30, 45, 20, 90);
        right_trngl.print_in_one_line();
    }
    catch (Exceptions& ex) {
        std::cout << ex.what() << std::endl;
    }

    // Равнобедренный треугольник НЕ будет создан - сторона а и с не равны
    try {
        IsoscelesTriangle isos_trngl(10, 20, 80, 30, 90, 30);
        isos_trngl.print_in_one_line();
    }
    catch (Exceptions& ex) {
        std::cout << ex.what() << std::endl;
    }

    // Равносторонний треугольник НЕ будет создан - углы не равны
    try {
        Eq_triangle eq_trngl(20, 20, 20, 30, 25, 30);
        eq_trngl.print_in_one_line();
    }
    catch (Exceptions& ex) {
        std::cout << ex.what() << std::endl;
    }

    // Четырехугольник будет создан - все ок
    try {
        Quad quad(10, 20, 30, 40, 5, 90, 90, 90);
        quad.print_in_one_line();
    }
    catch (Exceptions& ex) {
        std::cout << ex.what() << std::endl;
    }

    // Прямоугольник НЕ будет создан - один из углов не равен 90 градусов
    try {
        Rectangle rect(55, 20, 55, 20, 30, 90, 90, 90);
        rect.print_in_one_line();
    }
    catch (Exceptions& ex) {
        std::cout << ex.what() << std::endl;
    }

    // Квадрат будет создан - все ок
    try {
        Square square(20, 20, 20, 20, 90, 90, 90, 90);
        square.print_in_one_line();
    }
    catch (Exceptions& ex) {
        std::cout << ex.what() << std::endl;
    }

    // Параллелограмм НЕ будет создан - стороны попарно не равны
    try {
        Parallelogram prlgrm(20, 20, 2, 20, 30, 90, 30, 90);
        prlgrm.print_in_one_line();
    }
    catch (Exceptions& ex) {
        std::cout << ex.what() << std::endl;
    }

    // Ромб будет создан - все ок
    try {
        Rhombus rhmbs(20, 20, 20, 20, 30, 30, 30, 30);
        rhmbs.print_in_one_line();
    }
    catch (Exceptions& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
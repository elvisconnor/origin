#include "Quad.h"
#include "iostream"
#include "Exceptions.h"

Quad::Quad(int a, int b, int c, int d, int A, int B, int C, int D) {
    if (A + B + C + D > 360) {
        throw Exceptions(
            "Ошибка создания фигуры! Сумма углов больше 360 градусов.");
    }
    else {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
        this->name = "Четырехугольник";
    }
    };

void Quad::get_sides() {
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d
            << "\n";
    };

void Quad::get_angles() {
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D
            << "\n";
    };

void Quad::print_info() {
    Figure::print_info();
    get_sides();
    get_angles();
    std::cout << "\n";
};

void Quad::print_in_one_line() {
    std::cout << name << " (стороны " << a << ", " << b << ", " << c << ", "
        << d << "; углы " << A << ", " << B << ", " << C << ", " << D
        << ") создан.\n";
};
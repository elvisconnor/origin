#include "Triangle.h"
#include "iostream"

Triangle::Triangle(int a, int b, int c, int A, int B, int C) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
        this->name = "Треугольник";
    };

void Triangle::get_sides() {
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
    };

void Triangle::get_angles() {
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n";
    };

void Triangle::print_info() {
        Figure::print_info();
        get_sides();
        get_angles();
        std::cout << "\n";
    }
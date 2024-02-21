#include "Eq_triangle.h"
#include "Exceptions.h"

Eq_triangle::Eq_triangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C) {
    if (a != b && b != c && c != a) {
        throw Exceptions("Ошибка создания фигуры! Стороны не равны.");
    }
    else if (A != B && B != C) {
        throw Exceptions("Ошибка создания фигуры! Углы не равны.");
    }
    else {
        this->name = "Равносторонний треугольник";
    }
};
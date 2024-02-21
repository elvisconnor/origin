#include "Rectangle.h"
#include "Exceptions.h"

Rectangle::Rectangle(int a, int b, int c, int d, int A, int B, int C, int D) : Quad(a, b, c, d, A, B, C, D) {
    if (a != c || b != d) {
        throw Exceptions(
            "Ошибка создания фигуры! Стороны a, c и b, d попарно не равны.");
    }
    else if (A != 90 || B != 90 || C != 90 || D != 90) {
        throw Exceptions(
            "Ошибка создания фигуры! Один из углов не равен 90 градусам.");
    }
    else {
        this->name = "Прямоугольник";
    }
};
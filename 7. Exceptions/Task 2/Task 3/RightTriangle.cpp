#include "RightTriangle.h"
#include "Exceptions.h"

RightTriangle::RightTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C) {
    if (C != 90) {
        throw Exceptions(
            "Ошибка создания фигуры! Один из углов не равен 90 градусам.");
    }
    else {
        this->name = "Прямоугольный треугольник";
    }
};

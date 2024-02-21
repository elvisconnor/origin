#include "IsoscelesTriangle.h"
#include "Exceptions.h"

IsoscelesTriangle::IsoscelesTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C) {
    if (a != c && A != C) {
        throw Exceptions("Ошибка создания фигуры! Стороны а и с не равны, углы А "
            "и С не равны.");
    }
    else if (a != c) {
        throw Exceptions("Ошибка создания фигуры! Стороны а и с не равны.");
    }
    else if (A != C) {
        throw Exceptions("Ошибка создания фигуры! Углы А и С не равны.");
    }
    else {
        this->name = "Равнобедренный треугольник";
    }
};
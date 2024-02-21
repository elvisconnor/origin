#include "Rhombus.h"
#include "Exceptions.h"

Rhombus::Rhombus(int a, int b, int c, int d, int A, int B, int C, int D) : Quad(a, b, c, d, A, B, C, D) {
    if (a != b || b != c || c != d) {
        throw Exceptions("Ошибка создания фигуры! Стороны не равны.");
    }
    else if (A != C || B != D) {
        throw Exceptions(
            "Ошибка создания фигуры! Углы A, C и B, D попарно не равны.");
    }
    else {
        this->name = "Ромб";
    }
};
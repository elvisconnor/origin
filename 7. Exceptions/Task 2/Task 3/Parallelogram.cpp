#include "Parallelogram.h"
#include "Exceptions.h"

Parallelogram::Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) : Quad(a, b, c, d, A, B, C, D) {
    if (a != c || b != d) {
        throw Exceptions(
            "Ошибка создания фигуры! Стороны a, c и b, d попарно не равны.");
    }
    else if (A != C || B != D) {
        throw Exceptions(
            "Ошибка создания фигуры! Углы A, C и B, D попарно не равны.");
    }
    else {
        this->name = "Параллелограмм";
    }
};
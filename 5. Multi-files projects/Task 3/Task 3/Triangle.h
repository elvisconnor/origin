#pragma once
#include "Figure.h"

class Triangle : public Figure {
protected:
    int a, b, c;
    int A, B, C;
public:
    Triangle(int a, int b, int c, int A, int B, int C);
    void get_sides();
    void get_angles();
    void print_info() override;
};

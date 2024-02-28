#pragma once
#include "Figure.h"

class Quad : public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;
public:
    Quad(int a, int b, int c, int d, int A, int B, int C, int D);

    void get_sides();

    void get_angles();

    void print_info() override;
};
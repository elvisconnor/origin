#include <iostream>

class Figure {
public:
    Figure() {};
};

//Треугольник
class Triangle : public Figure {
protected:
    int a, b, c;
    int A, B, C;

public:
    Triangle(int a, int b, int c, int A, int B, int C) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    };

    void get_sides() {
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
    };

    void get_angles() {
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n";
    };
};

//Прямоугольный треугольник
class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B)
        : Triangle(a, b, c, A, B, 90) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = 90;
    };
};

//Равнобедренный треугольник
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {
        this->a = a;
        this->b = b;
        this->c = a;
        this->A = A;
        this->B = B;
        this->C = A;
    };
};

//Равносторонний треугольник
class Eq_triangle : public Triangle {
public:
    Eq_triangle(int a) : Triangle(a, a, a, 60, 60, 60) {
        this->a = a;
        this->b = a;
        this->c = a;
        this->A = 60;
        this->B = 60;
        this->C = 60;
    };
};

//Четырехугольник
class Quad : public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;

public:
    Quad(int a, int b, int c, int d, int A, int B, int C, int D) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    };

    void get_sides() {
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d
            << "\n";
    };

    void get_angles() {
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D
            << "\n";
    };
};

//Прямоугольник
class Rectangle : public Quad {
public:
    Rectangle(int a, int b, int c, int d) : Quad(a, b, c, d, 90, 90, 90, 90) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = 90;
        this->B = 90;
        this->C = 90;
        this->D = 90;
    };
};

//Квадрат
class Square : public Quad {
public:
    Square(int a) : Quad(a, a, a, a, 90, 90, 90, 90) {
        this->a = a;
        this->b = a;
        this->c = a;
        this->d = a;
        this->A = 90;
        this->B = 90;
        this->C = 90;
        this->D = 90;
    };
};

//Параллелограмм
class Parallelogram : public Quad {
public:
    Parallelogram(int a, int b, int A, int B) : Quad(a, b, a, b, A, B, A, B) {
        this->a = a;
        this->b = b;
        this->c = a;
        this->d = b;
        this->A = A;
        this->B = B;
        this->C = A;
        this->D = B;
    };
};

//Ромб
class Rhombus : public Quad {
public:
    Rhombus(int a, int A, int B) : Quad(a, a, a, a, A, B, A, B) {
        this->a = a;
        this->b = a;
        this->c = a;
        this->d = a;
        this->A = A;
        this->B = B;
        this->C = A;
        this->D = B;
    };
};

int main() {
    Triangle trngl(10, 20, 30, 25, 35, 45);
    RightTriangle right_trngl(66, 77, 88, 32, 45);
    IsoscelesTriangle iso_trngl(10, 20, 30, 45);
    Eq_triangle eq_trngl(10);

    Quad quad1(10, 20, 30, 40, 90, 90, 90, 90);
    Rectangle rctng1(35, 78, 65, 23);
    Square sqr1(10);
    Parallelogram prlgm1(10, 20, 40, 60);
    Rhombus rmbs1(10, 45, 45);

    std::cout << "Треугольник:\n";
    trngl.get_sides();
    trngl.get_angles();
    std::cout << "\n";

    std::cout << "Прямоугольный треугольник:\n";
    right_trngl.get_sides();
    right_trngl.get_angles();
    std::cout << "\n";

    std::cout << "Равнобедренный треугольник:\n";
    iso_trngl.get_sides();
    iso_trngl.get_angles();
    std::cout << "\n";

    std::cout << "Равносторонний треугольник:\n";
    eq_trngl.get_sides();
    eq_trngl.get_angles();
    std::cout << "\n";

    std::cout << "Четырехугольник:\n";
    quad1.get_sides();
    quad1.get_angles();
    std::cout << "\n";

    std::cout << "Прямоугольник:\n";
    rctng1.get_sides();
    rctng1.get_angles();
    std::cout << "\n";

    std::cout << "Квадрат:\n";
    sqr1.get_sides();
    sqr1.get_angles();
    std::cout << "\n";

    std::cout << "Параллелограмм:\n";
    prlgm1.get_sides();
    prlgm1.get_angles();
    std::cout << "\n";

    std::cout << "Ромб\n";
    rmbs1.get_sides();
    rmbs1.get_angles();
    std::cout << "\n";

    return 0;
}
#include <iostream>
#include <string>

class Figure {
protected:
    std::string name;
public:
    Figure() {
      this->name = "Фигура";
    };
    
    virtual void print_info() {
        std::cout << name << ": \n";
    }
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
        this->name = "Треугольник";
    };

    void get_sides() {
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
    };

    void get_angles() {
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n";
    };

    void print_info() override {
        Figure::print_info();
        get_sides();
        get_angles();
        std::cout << "\n";
    }
};

//Прямоугольный треугольник
class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
        this->name = "Прямоугольный треугольник";
    };
};

//Равнобедренный треугольник
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {
        this->name = "Равнобедренный треугольник";
    };
};

//Равносторонний треугольник
class Eq_triangle : public Triangle {
public:
    Eq_triangle(int a) : Triangle(a, a, a, 60, 60, 60) {
        this->name = "Равносторонний треугольник";
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
        this->name = "Четырехугольник";
    };

    void get_sides() {
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d
            << "\n";
    };

    void get_angles() {
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D
            << "\n";
    };

    void print_info() override {
        Figure::print_info();
        get_sides();
        get_angles();
        std::cout << "\n";
    }
};

//Прямоугольник
class Rectangle : public Quad {
public:
    Rectangle(int a, int b, int c, int d) : Quad(a, b, c, d, 90, 90, 90, 90) {
        this->name = "Прямоугольник";
    };
};

//Квадрат
class Square : public Quad {
public:
    Square(int a) : Quad(a, a, a, a, 90, 90, 90, 90) {
        this->name = "Квадрат";
    };
};

//Параллелограмм
class Parallelogram : public Quad {
public:
    Parallelogram(int a, int b, int A, int B) : Quad(a, b, a, b, A, B, A, B) {
        this->name = "Параллелограмм";
    };
};

//Ромб
class Rhombus : public Quad {
public:
    Rhombus(int a, int A, int B) : Quad(a, a, a, a, A, B, A, B) {
        this->name = "Ромб";
    };
};

//Функция вывода информации
void print(Figure* figure) {
    figure->print_info();
}

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

    Figure** figures = new Figure * [9] {
        &trngl, & right_trngl, & iso_trngl, & eq_trngl, & quad1, & rctng1, & sqr1, & prlgm1, & rmbs1
    };

    for (int i = 0; i < 9; i++) {
        print(figures[i]);
    };

    delete[] figures;

    return 0;
}
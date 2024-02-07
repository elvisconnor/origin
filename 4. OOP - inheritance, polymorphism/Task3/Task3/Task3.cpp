#include <iostream>
#include <string>

class Figure {
protected:
    int sides;
    std::string name;

public:
    Figure() {
        this->sides = 0;
        this->name = "Фигура";
    };

    virtual bool check() {
        if (sides == 0) {
            return true;
        }
        else {
            return false;
        }
    };

    virtual void print_info() {
        std::cout << name << ":\n";
        if (check() == true) {
            std::cout << "Правильная\n";
        }
        else {
            std::cout << "Неправильная\n";
        }
        std::cout << "Количество сторон: " << sides << "\n";
    };
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
        this->sides = 3;
        this->name = "Треугольник";
    };

    void get_sides() {
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
    };

    void get_angles() {
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n";
    };

    bool check() override {
        if (sides == 3 && A + B + C == 180) {
            return true;
        }
        else {
            return false;
        }
    };

    void print_info() override {
        Figure::print_info();
        get_sides();
        get_angles();
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
        this->name = "Прямоугольный треугольник";
    };

    bool check() override {
        if (Triangle::check() == true && C == 90) {
            return true;
        }
        else {
            return false;
        }
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
        this->name = "Равнобедренный треугольник";
    };

    bool check() override {
        if (Triangle::check() == true && a == c && A == C) {
            return true;
        }
        else {
            return false;
        }
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
        this->name = "Равносторонний треугольник";
    };

    bool check() override {
        if (Triangle::check() == true && a == c && c == b && A == 90 && B == 90 &&
            C == 90) {
            return true;
        }
        else {
            return false;
        }
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
        this->sides = 4;
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

    bool check() override {
        if (sides == 4 && A + B + C + D == 360) {
            return true;
        }
        else {
            return false;
        }
    };

    void print_info() override {
        Figure::print_info();
        get_sides();
        get_angles();
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
        this->name = "Прямоугольник";
    };

    bool check() override {
        if (sides == 4 && a == c && b == d && A == 90 & B == 90 && C == 90 && D == 90) {
            return true;
        }
        else {
            return false;
        }
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
        this->name = "Квадрат";
    };

    bool check() override {
        if (sides == 4 && a == b == c == d && A == 90 && B == 90 && C == 90 && D == 90) {
            return true;
        }
        else {
            return false;
        }
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
        this->name = "Параллелограмм";
    };

    bool check() override {
        if (sides == 4 && a == c && b == d && A == C && B == D) {
            return true;
        }
        else {
            return false;
        }
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
        this->name = "Ромб";
    };

    bool check() override {
        if (sides == 4 && a == b == c == d && A == C && B == D) {
            return true;
        }
        else {
            return false;
        }
    };
};

int main() {
    Figure fig;
    Triangle trngl(10, 20, 30, 100, 90, 45);
    RightTriangle right_trngl(66, 77, 88, 32, 45);
    IsoscelesTriangle iso_trngl(10, 20, 30, 45);
    Eq_triangle eq_trngl(10);

    Quad quad1(10, 20, 30, 40, 90, 90, 90, 90);
    Rectangle rctng1(35, 78, 65, 23);
    Square sqr1(10);
    Parallelogram prlgm1(10, 20, 40, 60);
    Rhombus rmbs1(10, 45, 45);

    Figure* fig_ptr = &fig;
    fig_ptr->print_info();
    std::cout << "\n";

    Figure** figures = new Figure* [9] {
        &trngl, &right_trngl, &iso_trngl, &eq_trngl, &quad1, &rctng1, &sqr1, &prlgm1, &rmbs1
        };

    for (int i = 0; i < 9; i++) {
        figures[i]->print_info();
        std::cout << "\n";
    }

    delete[] figures;

    return 0;
}
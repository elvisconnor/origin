#include <iostream>

class Figure {
    int fields;

public:
    Figure() {
        this->fields = 0;
    }

    void print() { std::cout << "Фигура: " << fields << "\n"; }
};

class triangle : public Figure {
    int fields;

public:
    triangle() {
        this->fields = 3;
    };
    void print() { std::cout << "Треугольник: " << fields << "\n"; }
};

class square : public Figure {
    int fields = 4;

public:
    square() {
        this->fields = 4;
    };
    void print() { std::cout << "Четырехугольник: " << fields << "\n"; }
};

int main() {
    Figure figure;
    triangle triangle;
    square square;

    std::cout << "Количество сторон:\n";
    figure.print();
    triangle.print();
    square.print();

    return 0;
}
#include <iostream>

class Calculator {
private:
    double num1;
    double num2;

public:
    Calculator(float num1, float num2) {
        this->num1 = num1;
        this->num2 = num2;
    }

    double add() {
        return this->num1 + this->num2;
    }

    double multiply() {
        return this->num1 * this->num2;
    }

    double subtract_1_2() {
        return this->num1 - this->num2;
    }

    double subtract_2_1() {
        return this->num2 - this->num1;
    }

    double divide_1_2() {
        return this->num1 / this->num2;
    }

    double divide_2_1() {
        return this->num2 / this->num1;
    }

    bool set_num1(double num1) {
        if (num1 == 0) {
            return false;
        }
        else {
            this->num1 = num1;
            return true;
        }
    }

    bool set_num2(double num2) {
        if (num2 == 0) {
            return false;
        }
        else {
            this->num2 = num2;
            return true;
        }
    }
};

int main() {
    setlocale(0, "");
    double user_num1 = 0;
    double user_num2 = 0;

    Calculator two_num(0, 0);

    while (true) {
        do {
            std::cout << "Введите num1: ";
            std::cin >> user_num1;
            
            if (two_num.set_num1(user_num1) == false) {
                std::cout << "Неверный ввод!\n";
                continue;
            } else {
                break;
            }
        } while (true);

        do {
            std::cout << "Введите num2: ";
            std::cin >> user_num2;
            
            if (two_num.set_num2(user_num2) == false) {
                std::cout << "Неверный ввод!\n";
                continue;
            } else {
                break;
            }
        } while (true);

        std::cout << "num1 + num2 = " << two_num.add() << "\n";
        std::cout << "num1 - num2 = " << two_num.subtract_1_2() << "\n";
        std::cout << "num2 - num1 = " << two_num.subtract_2_1() << "\n";
        std::cout << "num1 * num2 = " << two_num.multiply() << "\n";
        std::cout << "num1 / num2 = " << two_num.divide_1_2() << "\n";
        std::cout << "num2 / num1 = " << two_num.divide_2_1() << "\n";
    };

    return 0;
}
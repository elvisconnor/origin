#include <algorithm>
#include <iostream>
#include <string>

// Нахождение НОД и НОК
int gcd(int a, int b) {
    int result = std::min(a, b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }
    return result;
}
int lcm(int a, int b) { return (a / (gcd(a, b)) * b); }

class Fraction {
private:
    int numerator_;
    int denominator_;

public:
    Fraction(int numerator, int denominator) {
        numerator_ = numerator;
        denominator_ = denominator;
    }

    std::string print() {
        return std::to_string(numerator_) + "/" + std::to_string(denominator_);
    }

    int friend lcm(int a, int b);
    int friend gcd(int a, int b);

    Fraction operator+(Fraction other) {

        int new_numerator, new_denominator;

        if (this->denominator_ == other.denominator_) {
            new_numerator = this->numerator_ + other.numerator_;
            new_denominator = this->denominator_;
            if (gcd(new_numerator, new_denominator) != 1 && gcd(new_numerator, new_denominator) != -1) {
                return Fraction(new_numerator / gcd(new_numerator, new_denominator),
                    new_denominator / gcd(new_numerator, new_denominator));
            }
            else {
                return Fraction(new_numerator, new_denominator);
            }
        }
        else {
            new_denominator = lcm(this->denominator_, other.denominator_);
            new_numerator =
                this->numerator_ * (new_denominator / this->denominator_) +
                other.numerator_ * (new_denominator / other.denominator_);

            if (gcd(new_numerator, new_denominator) != 1 && gcd(new_numerator, new_denominator) != -1) {
                return Fraction(new_numerator / gcd(new_numerator, new_denominator),
                    new_denominator / gcd(new_numerator, new_denominator));
            }
            else {
                return Fraction(new_numerator, new_denominator);
            }
        }
    }

    Fraction operator-(Fraction other) {

        int new_numerator, new_denominator;

        if (this->denominator_ == other.denominator_) {
            new_numerator = this->numerator_ - other.numerator_;
            new_denominator = this->denominator_;
            if (gcd(new_numerator, new_denominator) != 1 && gcd(new_numerator, new_denominator) != -1) {
                return Fraction(new_numerator / gcd(new_numerator, new_denominator),
                    new_denominator / gcd(new_numerator, new_denominator));
            }
            else {
                return Fraction(new_numerator, new_denominator);
            }
        }
        else {
            int new_denominator = lcm(this->denominator_, other.denominator_);
            int new_numerator =
                this->numerator_ * (new_denominator / this->denominator_) -
                other.numerator_ * (new_denominator / other.denominator_);
            if (gcd(new_numerator, new_denominator) != 1 && gcd(new_numerator, new_denominator) != -1) {
                return Fraction(new_numerator / gcd(new_numerator, new_denominator),
                    new_denominator / gcd(new_numerator, new_denominator));
            }
            else {
                return Fraction(new_numerator, new_denominator);
            }
        }
    }

    Fraction operator*(Fraction other) {

        int new_numerator = this->numerator_ * other.numerator_;
        int new_denominator = this->denominator_ * other.denominator_;

        if (gcd(new_numerator, new_denominator) != 1 && gcd(new_numerator, new_denominator) != -1) {
            return Fraction(new_numerator / gcd(new_numerator, new_denominator),
                new_denominator / gcd(new_numerator, new_denominator));
        }
        else {
            return Fraction(new_numerator, new_denominator);
        }
    }

    Fraction operator/(Fraction other) {

        int new_numerator = this->numerator_ * other.denominator_;
        int new_denominator = this->denominator_ * other.numerator_;

        if (gcd(new_numerator, new_denominator) != 1 && gcd(new_numerator, new_denominator) != -1) {
            return Fraction(new_numerator / gcd(new_numerator, new_denominator),
                new_denominator / gcd(new_numerator, new_denominator));
        }
        else {
            return Fraction(new_numerator, new_denominator);
        }
    }

    Fraction operator++() {
        this->numerator_ += this->denominator_;
        return *this;
    }

    Fraction operator--() {
        this->numerator_ -= this->denominator_;
        return *this;
    }

    Fraction operator++(int) {
        Fraction temp = *this;
        this->numerator_ += this->denominator_;
        return temp;
    }

    Fraction operator--(int) {
        Fraction temp = *this;
        this->numerator_ -= this->denominator_;
        return temp;
    }

    Fraction operator-() {
        return Fraction(-this->numerator_, this->denominator_);
    }
};

int main() {
    int numerator1, denominator1, numerator2, denominator2;

    std::cout << "Введите числитель дроби 1: ";
    std::cin >> numerator1;
    std::cout << "Введите знаменатель дроби 1: ";
    std::cin >> denominator1;

    std::cout << "Введите числитель дроби 2: ";
    std::cin >> numerator2;
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> denominator2;

    Fraction f1(numerator1, denominator1);
    Fraction f2(numerator2, denominator2);

    std::cout << f1.print() << " + " << f2.print() << " = " << (f1 + f2).print()
        << "\n";

    std::cout << f1.print() << " - " << f2.print() << " = " << (f1 - f2).print()
        << "\n";

    std::cout << f1.print() << " * " << f2.print() << " = " << (f1 * f2).print()
        << "\n";

    std::cout << f1.print() << " / " << f2.print() << " = " << (f1 / f2).print()
        << "\n";

    std::cout << "++" << f1.print() << " * " << f2.print() << " = ";
    std::cout << ((++f1) * f2).print() << "\n";

    std::cout << "Значение дроби 1 = " << f1.print() << "\n";

    std::cout << f1.print() << "--" << " * " << f2.print() << " = ";
    std::cout << ((f1--) * f2).print() << "\n";

    std::cout << "Значение дроби 1 = " << f1.print() << "\n";

    std::cout << "Значение дроби - 1 с унарным минусом = " << (-f1).print()
        << "\n";

    return 0;
}
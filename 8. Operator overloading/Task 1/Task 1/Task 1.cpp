#include <iostream>
#include <algorithm>

// Нахождение НОД
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

class Fraction
{
private:
	int numerator_;
	int denominator_;

	int friend gcd(int a, int b);

public:
	Fraction(int numerator, int denominator)
	{
		if (gcd(numerator, denominator) != 1 && gcd(numerator, denominator) != -1) {
			numerator_ = numerator / gcd(numerator, denominator);
			denominator_ = denominator / gcd(numerator, denominator);
		} else {
			numerator_ = numerator;
			denominator_ = denominator;
		}
	}

	bool operator==(Fraction other) {
		return this->numerator_ == other.numerator_ && this->denominator_ == other.denominator_;
	}

	bool operator!=(Fraction other) {
		return !(this->numerator_ == other.numerator_ && this->denominator_ == other.denominator_);
	}

	bool operator>(Fraction other) {
		if (this->denominator_ == other.denominator_ && this->numerator_ > other.numerator_) {
			return true;
		}
		else if (this->numerator_ == other.numerator_ && this->denominator_ > other.denominator_) {
			return true;
		}
		else if (this->numerator_ != other.numerator_ && this->denominator_ != other.denominator_ && this->numerator_ > this->denominator_ && other.numerator_ <= other.denominator_) {
			return true;
		}
		else if (this->numerator_ != other.numerator_ && this->denominator_ != other.denominator_ && this->numerator_ <= this->denominator_ && other.numerator_ <= other.denominator_) {
			int check_denominator1 = 0, check_denominator2 = 0;
			check_denominator1 = this->denominator_ * other.numerator_;
			check_denominator2 = this->numerator_ * other.denominator_;
			if (check_denominator1 > check_denominator2) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}

	bool operator<(Fraction other) {
		return !(*this > other || *this == other);
	}

	bool operator<=(Fraction other) {
		return (*this < other || *this == other);
	}

	bool operator>=(Fraction other) {
		return (*this > other || *this == other);
	}
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(8, 6);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	
	return 0;
}
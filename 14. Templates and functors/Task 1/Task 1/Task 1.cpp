#include <iostream>
#include <vector>

template <class T> void squaring(T a) {
    std::cout << "[IN]: " << a << "\n";
    std::cout << "[OUT]: " << a * a << "\n";
}

template <> void squaring(std::vector<int> a) {
    bool is_first = true;
    std::cout << "[IN]: ";
    for (auto i : a) {
        if (is_first == false) {
            std::cout << ", ";
        }
        std::cout << i;
        is_first = false;
    }
    std::cout << "\n";

    bool is_first2 = true;
    std::cout << "[OUT]: ";
    for (auto i : a) {
        if (is_first2 == false) {
            std::cout << ", ";
        }
        std::cout << i * i;
        is_first2 = false;
    }
    std::cout << "\n";
}

int main() {
    int a = 4;
    squaring(a);

    std::vector<int> v = { -1, 4, 8 };
    squaring(v);
}
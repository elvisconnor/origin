#include <iostream>
#include <vector>

template <class T> T squaring(const T& a) { return a * a; };

template <class T> std::vector<T> squaring(const std::vector<T>& a) {

    std::vector<T> temp = {};

    for (auto i : a) {
        temp.push_back(i * i);
    }

    return temp;
};

int main() {
    int a = 4;
    std::cout << "[IN]: " << a << "\n";
    std::cout << "[OUT]: " << squaring(a) << "\n";

    std::vector<int> v = { -1, 4, 8 };

    bool is_first = true;
    std::cout << "[IN]: ";
    for (auto i : v) {
        if (is_first == false) {
            std::cout << ", ";
        }
        std::cout << i;
        is_first = false;
    }
    std::cout << "\n";

    std::vector<int> v_after = squaring(v);
    bool is_first2 = true;
    std::cout << "[OUT]: ";
    for (auto i : v_after) {
        if (is_first2 == false) {
            std::cout << ", ";
        }
        std::cout << i;
        is_first2 = false;
    }
    std::cout << "\n";

    squaring(v);
}
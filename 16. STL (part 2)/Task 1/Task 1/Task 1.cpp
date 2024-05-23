#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

auto func(std::vector<int>& vec) {
    std::set<int> s;
    for (int i = 0; i < vec.size(); i++) {
        s.insert(vec[i]);
    }
    return s;
}

int main() {
    std::vector<int> number = { 1, 1, 2, 5, 6, 1, 2, 4 };
    std::vector<int>::iterator i = number.begin();
    while (i != number.end()) {
        std::cout << *i << "\t";
        i++;
    };
    std::cout << "\n" << "\n";

    auto s = func(number);

    for (auto i : s) {
        std::cout << i << "\t";
    }

    return 0;
}
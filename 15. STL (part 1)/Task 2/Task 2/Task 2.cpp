#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
    setlocale(0, "");
    int count = 0;
    std::cout << "Введите количество элементов: ";
    std::cin >> count;

    std::set<int> set;

    for (int i = 0; i < count; i++) {
        std::cout << "Введите элемент № " << i + 1 << ": ";
        int num;
        std::cin >> num;
        set.insert(num);
    }

    std::vector<int> vec(set.begin(), set.end());

    std::sort(vec.begin(), vec.end(), std::greater<int>());

    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << "\n";
    }

    return 0;
}
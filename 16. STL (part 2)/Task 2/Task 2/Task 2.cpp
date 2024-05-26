#include <iostream>
#include <set>
#include <list>
#include <vector>

template <typename T>
void print_container(const T& container) {
    bool first = true;
    for (const auto& element : container) {
        if (!first) {
            std::cout << ", ";
        }
        else {
            first = false;
        }
        std::cout << element;
    }
}

int main() {
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(test_set);
    std::cout << "\n";

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list);
    std::cout << "\n";

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector);
    std::cout << "\n";

    return 0;
}
#include <iostream>
#include <vector>

class DivisibleByThreeCounter {
private:
    int sum = 0;
    int count = 0;
public:
    void operator()(int num) {
        if (num % 3 == 0) {
            sum += num;
            count++;
        }
    }
    int get_sum() {
        return sum;
    }
    int get_count() {
        return count;
    }
};
int main() {

    DivisibleByThreeCounter counter;

    std::vector<int> numbers = { 4, 1, 3, 6, 25, 54 };
    for (int num : numbers) {
        counter(num);
    }

    std::cout << "get_sum() = " << counter.get_sum() << std::endl;
    std::cout << "get_count() = " << counter.get_count() << std::endl;
    return 0;
}
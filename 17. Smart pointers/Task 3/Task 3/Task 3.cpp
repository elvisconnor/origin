#include <iostream>

template <typename T>
class my_unique_ptr {
private:
    T* ptr;
public:
    my_unique_ptr(T* ptr) {
        this->ptr = ptr;
    };

    my_unique_ptr& operator =(const my_unique_ptr& ptr) = delete;

    my_unique_ptr(const my_unique_ptr& ptr) = delete;

    T& operator *() {
        return *ptr;
    }

    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    ~my_unique_ptr() {
        delete[] ptr;
    };
};

int main() {
    int a = 5;
    int* ptr = &a;

    my_unique_ptr<int> ptr1(ptr);
    std::cout << *ptr1 << std::endl;
    std::cout << ptr1.release() << std::endl;

    return 0;
}
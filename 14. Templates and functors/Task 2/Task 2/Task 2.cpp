#include <iostream>

template <class T> class table {
private:
    T rows;
    T cols;
    T** arr;

public:
    table(T r, T c) : rows(r), cols(c) {
        arr = new T * [r];
        for (T i = 0; i < r; ++i) {
            arr[i] = new T[c];
        }
    }

    T* operator[](T i) { return arr[i]; }

    const T* operator[](T i) const { return arr[i]; }

    T Size() const { return rows * cols; }

    ~table() { delete[] arr; }
};

int main() {
    auto test = table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0];
}
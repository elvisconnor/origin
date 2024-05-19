#include <iostream>
template <class T>
class table {
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

    table(const table& other) : rows(other.rows), cols(other.cols) {
        arr = new T * [rows];
        for (T i = 0; i < rows; ++i) {
            arr[i] = new T[cols];
            for (T j = 0; j < cols; ++j) {
                arr[i][j] = other.arr[i][j];
            }
        }
    }

    table& operator=(const table& other) {
        if (this == &other) {
            return *this;
        }

        for (T i = 0; i < rows; ++i) {
            delete[] arr[i];
        }
        delete[] arr;

        rows = other.rows;
        cols = other.cols;
        arr = new T * [rows];
        for (T i = 0; i < rows; ++i) {
            arr[i] = new T[cols];
            for (T j = 0; j < cols; ++j) {
                arr[i][j] = other.arr[i][j];
            }
        }

        return *this;
    }

    T* operator[](size_t i) { return arr[i]; }

    const T* operator[](size_t i) const { return arr[i]; }

    T Size() const { return rows * cols; }

    ~table() {
        for (T i = 0; i < rows; ++i) {
            delete[] arr[i];
        }
        delete[] arr;
    }
};

int main() {
    auto test = table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0];
}